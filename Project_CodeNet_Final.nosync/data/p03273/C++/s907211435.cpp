#include <iostream>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
int main(void){
    int h, w;
    cin >> h >> w;
    vector<vector<int>>color(h);
    for(auto & x : color){
        x.resize(w);
        for(auto & in : x){
            char c;
            cin >> c;
            if(c == '.'){
                in = 0;
            } else{
                in = 1;
            }
        }
    }
    set<int> dh;
    for(auto i = 0; i < h; ++i){
        if(accumulate(color[i].begin(),color[i].end(),0) == 0){
            dh.insert(i);
        }
    }
    set<int> dw;
    for(auto j = 0; j < w; ++j){
        auto csum = 0;
        for(auto i = 0; i < h; ++i){
            csum += color[i][j];
        }
        if(csum == 0){
            dw.insert(j);
        }
    }
    for(auto i = 0; i < h; ++i){
        if(dh.count(i) == 0){
            for(auto j = 0; j < w; ++j){
                if(dw.count(j) == 0){
                    if(color[i][j] == 0){
                        cout << '.';
                    } else{
                        cout << '#';
                    }
                }
            }
            cout << endl;
        }
    }
}