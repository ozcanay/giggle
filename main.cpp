#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cmath>

#include "testcase.h"

static constexpr const char* NO_SOLUTION = "NO SOLUTION";

std::vector<long long> vectorize(const std::string &input, char delim = ' ') {
    std::vector<long long> result;
    std::stringstream input_stream(input);
    std::string line;

    while (std::getline(input_stream, line, delim)) {
        result.push_back(std::stoll(line));
    }

    return result;
}

int main()
{
    const std::string input_file = "small-testdata.in";
    std::ifstream input_stream(input_file);

    std::string line;
    std::getline(input_stream, line);
    int testcase_count = std::stoi(line);
    std::cout << "Number of testcases: " << testcase_count << std::endl;

    int database_count = 0;
    std::vector<long long> database_ids;
    long long threshold = 0;

    int id = 1;
    std::vector<Testcase> testcases;

    while(testcase_count--) {
        Testcase testcase;
        testcase.setId(id++);

        if(std::getline(input_stream, line)) {
            database_count = std::stoi(line);
            testcase.setDatabaseCount(database_count);
        }
        if(std::getline(input_stream, line)) {
            auto database_ids = vectorize(line);
            std::sort(database_ids.begin(), database_ids.end());
            testcase.setDatabaseIds(database_ids);
        }
        if(std::getline(input_stream, line)) {
            threshold = std::stoll(line);
            testcase.setThreshold(threshold);
        }

        testcases.push_back(testcase);
    }


    std::ofstream output_file;
    output_file.open("output.txt");

    for(auto& testcase : testcases) {
//        std::cout << "testcase id: " << testcase.getId() << std::endl;
//        std::cout << testcase.getDatabaseCount() << std::endl;
//        for(const auto database_id : testcase.getDatabaseIds()) {
//            std::cout << database_id << ' ';
//        }
//        std::cout << std::endl;
//        std::cout << testcase.getThreshold() << std::endl;
//        std::cout << "------------------" << std::endl;

        auto result = testcase.solve();
        if(result == -1) {
            output_file << "Case #" << testcase.getId() << ": NO SOLUTION\n";
        } else {
            output_file << "Case #" << testcase.getId() << ": " << result << '\n';
        }
    }

    output_file.close();

    return 0;
}
