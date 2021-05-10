#pragma once

#include <vector>
#include <unordered_set>

class Testcase {
public:
    void setId(long long id);
    long long getId() const;

    void setDatabaseCount(long long database_count);
    long long getDatabaseCount() const;

    void setDatabaseIds(const std::vector<long long>& database_ids);
    std::vector<long long> getDatabaseIds() const;

    void setThreshold(long long threshold);
    long long getThreshold() const;

    long long solve();
private:
    int id_; /// testcase id, for demo purpose.
    int database_count_;
    std::vector<long long> database_ids_; /// sorted
    long long threshold_;
    long long longest_response_time_;
    long long curr_db_id_ = 0; /// currenty, we are at id 0.
    std::unordered_set<long long> visited_{curr_db_id_};
};
