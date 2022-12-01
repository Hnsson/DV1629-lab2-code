// C++ implementation of FIFO page replacement
// in Operating Systems.
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    // int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    std::vector<int> pages;
    
    int n = 0;
    int page_size = 256;

    std::fstream fp;
    fp.open("mp3d.mem");
    if(fp.is_open()) {
        std::string linec;
        while(getline(fp, linec)) {
            int line = stoi(linec);
            pages.push_back(line);
            n++;
        }
    }

    int capacity = 4;
    std::unordered_set<int> s;
    std::queue<int> indexes;
    int page_faults = 0;

    for (int i=0; i<n; i++) {
        if (s.size() < capacity) {
            if (s.find(pages[i])==s.end()) {
                s.insert(pages[i]);

                page_faults++;

                indexes.push(pages[i]);
            }
        } else {
            if (s.find(pages[i]) == s.end()) {
                int val = indexes.front();

                indexes.pop();

                s.erase(val);
                s.insert(pages[i]);

                indexes.push(pages[i]);

                page_faults++;
            }
        }
    }

    std::cout << page_faults << std::endl;
    return 0;
}