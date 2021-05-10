#include "testcase.h"

#include <iostream>

void Testcase::setId(long long id)
{
    id_ = id;
}

long long Testcase::getId() const
{
    return id_;
}

void Testcase::setDatabaseCount(long long database_count)
{
    database_count_ = database_count;
}

long long Testcase::getDatabaseCount() const
{
    return database_count_;
}

void Testcase::setDatabaseIds(const std::vector<long long>& database_ids)
{
    database_ids_ = database_ids;
}

std::vector<long long> Testcase::getDatabaseIds() const
{
    return database_ids_;
}

void Testcase::setThreshold(long long threshold)
{
    threshold_ = threshold;
}

long long Testcase::getThreshold() const
{
    return threshold_;
}

long long Testcase::solve()
{
#ifdef VERBOSE
        std::cout << ">>> Solving testcase #" << id_ << "\nCurrently at database 0." << std::endl;
#endif

    while(visited_.size() != database_ids_.size()) {
        long long smallest_db_id_candidate = INT64_MAX;
        for(const auto database_id_ : database_ids_) {
            if(visited_.find(database_id_) == visited_.end()) {
                smallest_db_id_candidate = database_id_;
                break;
            }
        }

        long long largest_db_id_candidate = INT64_MIN;
        for (auto it = database_ids_.rbegin(); it != database_ids_.rend(); ++it) {
            if(visited_.find(*it) == visited_.end()) {
                largest_db_id_candidate = *it;
                break;
            }
        }

        long long next_db_id = std::llabs(curr_db_id_- smallest_db_id_candidate) >= std::abs(curr_db_id_ - largest_db_id_candidate)
                                                                               ? smallest_db_id_candidate : largest_db_id_candidate;

#ifdef VERBOSE
        std::cout << "Picking database " << next_db_id << " next." << std::endl;
#endif

        longest_response_time_ += std::llabs(curr_db_id_ - next_db_id);

        curr_db_id_ = next_db_id;
        visited_.insert(curr_db_id_);
    }

    longest_response_time_ += std::abs(curr_db_id_); /// we turn back to db id 0.
#ifdef VERBOSE
        std::cout << "Returning back to database 0." << std::endl;
#endif


#ifdef VERBOSE
        std::cout << "<<< Finished solving testcase #" << id_ << std::endl;
#endif

    if(longest_response_time_ <= threshold_) {
        return longest_response_time_;
    } else {
        return -1;;
    }
}


