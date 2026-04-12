//  main.cpp
//  CppTest

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {

    /////////////////////
    // Write code below /
    /////////////////////
    int height, width;
    cin >> height >> width;
    vector<string> a(height);
    for (int i = 0; i < height; i++) {
        cin >> a.at(i);
    }
    
    // 黒色のマスがあるrowとcolumnを記録する
    vector<bool> rows(height, false);
    vector<bool> columns(width, false);
    
    for (int row_i = 0; row_i < height; row_i++) {
        for (int column_i = 0; column_i < width; column_i++) {
            if (a.at(row_i).at(column_i) == '#') {
                rows.at(row_i) = true;
                columns.at(column_i) = true;
            }
        }
    }
    
    for (int row_i = 0; row_i < height; row_i++) {
        if (rows.at(row_i)) {
            for (int column_i = 0; column_i < width; column_i++) {
                if (columns.at(column_i)) {
                    cout << a.at(row_i).at(column_i);
                }
            }
            cout << endl;
        }
    }
    
    
    return 0;
}
