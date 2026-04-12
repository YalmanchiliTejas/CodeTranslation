#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstdint>
using namespace std;

const int MAX_SIZE = 100;

int main(){
    int h, w;
    char c[MAX_SIZE][MAX_SIZE];
    vector<int> valid_w;
    vector<int> valid_h;

    cin >> h >> w;

    for(int i = 0; i < h; i++) {
        bool w_blank_flag = true;
        for(int j = 0; j < w; j++) {
            char c_in;
            cin >> c_in;
            c[i][j] = c_in;
            if(c_in == '#') {
                w_blank_flag = false;
            }
        }
        if(!w_blank_flag) {
            valid_h.push_back(i);
        }
    }
    
    for(int j = 0; j < w; j++) {
        bool h_blank_flag = true;
        for(int i = 0; i < h; i++) {
            if(c[i][j] == '#') {
                h_blank_flag = false;
            }
        }
        if(!h_blank_flag) {
            valid_w.push_back(j);
        }
    }

    int h_valid_index = 0;
    int w_valid_index = 0;
    for(int i = 0; i < h; i++) {
        if(i == valid_h[h_valid_index]) {
            h_valid_index++;
            for(int j = 0; j < w; j++) {
                if(j == valid_w[w_valid_index]) {
                    w_valid_index++;
                    cout << c[i][j];
                }
            }
            w_valid_index = 0;
            cout << endl;
        }
    }
    
    return 0;
}