#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using ll = unsigned long long;
using namespace std;

int main(void) {
    int h,w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    for(int hi = 0; hi < h ; ++hi) {
        for(int wi = 0; wi < w; ++wi) {
            cin >> a[hi][wi];
        }
    }

    // for(int hi = 0; hi < h ; ++hi) {
    //     for(int wi=0; wi < w; ++wi) {
    //         cout <<  a[hi][wi];
    //     }
    //     cout << endl;
    // }

    

    // solve

    vector<int> skiprows;

    for(int i = 0; i < h; ++i) {
        // if (accumulate(a[i].begin(), a[i].end(), 0) == 0) {
        bool skip = true;
        for(int wi = 0; wi < w; ++wi) {
            if (a[i][wi] != '.') {
                skip = false;
                break;
            }
        }
        if (skip) {
            skiprows.push_back(i);
        }
    }

    vector<int> skipcols;
    for(int i = 0; i < w; ++i) {

        bool skip = true;
        for(int j = 0; j < h; ++j){
            if (a[j][i] != '.') {
                skip = false;
                break;
            }
        }

        if (skip) {
            skipcols.push_back(i);
        }
    }

    // show
    for(int hi = 0; hi < h; ++hi) {
        if (find(skiprows.begin(), skiprows.end(), hi) != skiprows.end()) {
            continue;
        }

        bool need_lf = false;
        for(int wi = 0; wi < w;++wi) {
            if (find(skipcols.begin(), skipcols.end(), wi) != skipcols.end()) {
                continue;
            }

            cout << a[hi][wi];
            need_lf = true;
        }
        if (need_lf){
            cout << endl;
        }
    }

    return 0;
}