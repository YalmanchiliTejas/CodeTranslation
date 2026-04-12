#include <iostream>
#include <vector>

void show_cells(std::vector<std::vector<char>>& cells) {
    for (auto &&row : cells) {
        for (auto && elem : row) {
            std::cout << elem;
        }
        std::cout << std::endl;
    }
}

void delete_row(std::vector<std::vector<char>>& cells) {
    size_t idx = 0;
    auto row = std::begin(cells);
    while (row != cells.end()) {
        //std::cout << "idx: " << idx << std::endl;
        bool all_white = true;
        for (auto && elem : *row) {
            if (elem != '.') {
                all_white = false;
                break;
            }
        }
        if (all_white) {
            //std::cout << "all white column found!" << std::endl;
            row = cells.erase(std::begin(cells) + idx); 
        } else {
            idx++;
            row++;
        } 
        //std::cout << "next iteration!" << std::endl;
    }
}

void delete_column(std::vector<std::vector<char>>& cells) {
    bool delete_list[100];
    for (auto &&e : delete_list) e = true;
    
    for (size_t row=0; row<cells.size(); ++row) {
        for (size_t i=0; i<cells[row].size(); ++i) {
            if (cells[row][i]=='#') {
                delete_list[i] = false;
            }
        }
    }
    
    for (size_t row=0; row<cells.size(); ++row) {
        size_t idx = 0;
        //for (auto iter = cells[row].begin(); iter != cells[row].end(); iter++) {
        auto iter = cells[row].begin();
        while (iter != cells[row].end()) {
            if (delete_list[idx]) {
                iter = cells[row].erase(iter);
                //std::cout << "delete: row " << row << ", column " << idx << std::endl;
            } else {
                iter++;
            }
            idx++;
        }
    }
}

int main() {
    std::vector<std::vector<char>> cells;
    std::vector<char> c_vector;
    
    int H, W;
    char temp;
    std::cin >> H >> W;
    
    for (int row=0; row<H; row++) { 
        for (int column=0; column<W; column++) {
            std::cin >> temp;
            c_vector.push_back(temp);
        }
        cells.push_back(c_vector);
        c_vector = {};
    }
    delete_row(cells);
    delete_column(cells);
    show_cells(cells); 
}