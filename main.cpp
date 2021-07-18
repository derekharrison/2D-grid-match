/*
 * main.cpp
 *
 *  Created on: Jul 18, 2021
 *      Author: d-w-h
 */

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

std::string grid_search(std::vector<std::string> G, std::vector<std::string> P) {
    int num_rows_G = G.size();
    int size_strings_G = G[0].length();

    int num_rows_pattern = P.size();
    int size_strings_pattern = P[0].length();

    for(int j = 0; j < num_rows_G - num_rows_pattern + 1; ++j) {

        for(int i = 0; i < size_strings_G - size_strings_pattern + 1; ++i) {
            std::string substr = G[j].substr(i, size_strings_pattern);
            if(P[0] == substr) {
                bool row_pattern_fits = true;
                int index = 1;
                for(int r = 1; r < num_rows_pattern; ++r) {
                    std::string substr = G[j+index].substr(i, size_strings_pattern);
                    row_pattern_fits = row_pattern_fits && P[r] == substr;
                    index++;
                }
                if(row_pattern_fits) { return "YES"; }
            }

        }

    }

    return "NO";
}

int main(int argc, char* argv[]) {

    std::vector<std::string> G;
    std::vector<std::string> P;

    //Create grid
    G.push_back("32315");
    G.push_back("13345");
    G.push_back("15365");
    G.push_back("31375");

    //Create pattern
    P.push_back("45");
    P.push_back("65");

    //Check if the pattern is contained in the grid
    std::string result = grid_search(G, P);

    //Print results
    std::cout << "is there a match? " << result << std::endl;
    std::cout << "done" << std::endl;

    return 0;
}
