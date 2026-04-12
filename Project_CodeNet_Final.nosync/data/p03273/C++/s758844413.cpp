#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
#include <ccomplex>
#include <unordered_map>
#include <cstring>
#include <iostream>
#include <numeric>


using namespace std;
#define MAX 100000

int main(){
    int H, W;
    vector<vector<char>> a;

    cin >> H >> W;

    for (int i = 0; i < H; i++){
        vector<char> atemp;
        a.push_back(atemp);

        for (int ii = 0; ii < W; ii++){
            char tmp;
            cin >> tmp;
            a[i].push_back(tmp);
        }
    }

    for (unsigned int i = 0; i < a.size(); i++){
        int icnt = 0;
        for (icnt = 0; icnt < W; icnt++){
            if ('#' == a[i][icnt]){
                break;
            }
        }

        if (W == icnt){
            a.erase(a.begin() + i);
            i--;
        }
    }

    for (unsigned int i = 0; i < a[0].size(); i++){
        unsigned int jcnt = 0;
        for (jcnt = 0; jcnt < a.size(); jcnt++){
            if ('#' == a[jcnt][i]){
                break;
            }
        }
        if (a.size() == jcnt){
            for (unsigned int ii = 0; ii < a.size(); ii++){
                a[ii].erase(a[ii].begin() + i);
            }
            i--;
        }
    }
    
    for (unsigned int i = 0; i < a.size(); i++){
        for (char ii : a[i]){
            cout << ii;
        }
        cout << "\n";
    }
    return 0;
}