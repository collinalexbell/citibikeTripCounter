#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <rapidcsv.h>
#include <cxxopts.hpp>

namespace fs = std::filesystem;

int countByStation(std::string stationName) {
    int count = 0;
    std::string folderPath = "data";

    // Iterate over all files in the "data" folder
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        const auto& path = entry.path();

        // Check if the file has a .csv extension
        if (path.extension() == ".csv") {
            std::cout << "Processing file: " << path.filename() << std::endl;

              rapidcsv::Document doc(path, rapidcsv::LabelParams(-1, -1));

              {
               std::vector<std::string> startStationNames = doc.GetColumn<std::string>(4);
               count += std::count(startStationNames.begin(), startStationNames.end(), stationName);
              }
              {
               std::vector<std::string> endStationNames = doc.GetColumn<std::string>(6);
               count += std::count(endStationNames.begin(), endStationNames.end(), stationName);
              }
        }
    }
    return count;
}


int main(int argc, char* argv[]) {
    std::string stationName;
    bool count = false;

    try {
        cxxopts::Options options("CitiBike", "Read CitiBike data");
        options.add_options()
            ("s,station", "Station Name", cxxopts::value<std::string>());
        options.add_options()
            ("c,count", "Count Trips");



        auto result = options.parse(argc, argv);

        if (result.count("station")) {
            stationName = result["station"].as<std::string>();
        } else {
            std::cout << "Error: Missing -s argument." << std::endl;
            return 1;
        }
        if (result.count("count")) {
         count = true;
        }
    } catch (const cxxopts::exceptions::exception &e) {
        std::cout << "Error parsing options: " << e.what() << std::endl;
        return 1;
    }

    if(count && stationName != "") {
     std::cout << countByStation(stationName) << std::endl;     
    }

    return 0;
}
