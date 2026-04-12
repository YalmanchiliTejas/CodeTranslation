#include <iostream>
#include <string>
#include <vector>
#include <stack>
 
using namespace std;

void deleteBlankRow(vector<vector<char>>& grid);
void deleteBlankColumn(vector<vector<char>>& grid);
  
int main() {
    int numOfRows = 0;
    int numOfColumns = 0;
    cin >> numOfRows >> numOfColumns;
    
    vector<vector<char>> grid(numOfRows, vector<char>(numOfColumns));
    for (int i = 0; i < numOfRows; ++i) {
        for (int j = 0; j< numOfColumns; ++j) {
            cin >> grid.at(i).at(j);
        }
    }
    
    deleteBlankRow(grid);
    deleteBlankColumn(grid);

    for (size_t i = 0U; i < grid.size(); ++i) {
        for(size_t j = 0U; j < grid.at(i).size(); ++j) {
            cout << grid.at(i).at(j);
        }
        cout << endl;
    }
}

void deleteBlankRow(vector<vector<char>>& grid) {
    stack<int> blankRowNum;
    for (size_t i = 0U; i < grid.size(); ++i) {
        bool isBlankRow = true;
        for(size_t j = 0U; j < grid.at(i).size(); ++j) {
            if(grid.at(i).at(j) == '#') {
                isBlankRow = false;
                break;
            }
        }
        if (isBlankRow) {
            blankRowNum.push(i);
        }    
    }
    
    while (!blankRowNum.empty()) {
        grid.erase(grid.begin() + blankRowNum.top());
        blankRowNum.pop();
    }
}

void deleteBlankColumn(vector<vector<char>>& grid) {
    stack<int> blankColumnNum;
    for (size_t i = 0U; i < grid.at(0).size(); ++i) {
        bool isBlankColumn = true;
        for(size_t j = 0U; j < grid.size(); ++j) {
            if (grid.at(j).at(i) == '#') {
                isBlankColumn = false;
                break;
            }
        }
        if (isBlankColumn) {
            blankColumnNum.push(i);
        }    
    }
    
    while(!blankColumnNum.empty()) {
        for (size_t i = 0U; i < grid.size(); ++i) {
            grid.at(i).erase(grid.at(i).begin() + blankColumnNum.top());
        }
        blankColumnNum.pop();
    }
}