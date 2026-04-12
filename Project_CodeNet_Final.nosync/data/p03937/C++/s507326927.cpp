#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <deque>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
    //input
    int h,w; cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));

    for(int i = 0;i < h; i++) {
        for(int j = 0; j < w ; j++){
            cin >> a[i][j];
    }
    }

    //compute
    int sum = 0;
    vector<int> c(h,0);
    for(int i = 0;i < h; i++) {
        for(int j = 0; j < w ; j++){
            if(a[i][j] == '#'){
                c[i] += 1;
            }
        }
    }

    for(int i = 0;i < h; i++) sum += c[i];

    //output
    if(sum == h + w -1){
        cout << "Possible" << endl;
    }else{
        cout << "Impossible" << endl;
    }
}