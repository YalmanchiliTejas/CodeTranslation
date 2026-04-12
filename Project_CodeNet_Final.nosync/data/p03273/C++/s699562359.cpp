#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include <queue>
#include <utility>
#include <map>
#include <set>
#include <deque>
#include <numeric>
using namespace std;

#define INF 100000

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<bool>>a(H, vector<bool>(W,0));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c;
            cin >> c;
            if (c == '#')a[i][j] = 1;
        }
    }

    set<int>line, row;
    //横に観て無視する列を決める
    for (int i = 0; i < H; i++) {
        bool bel_flag = true;
        for (int j = 0; j < W; j++) {
            if (a[i][j] ==1) {
                bel_flag = false;
                break;
            }
        }
        if (bel_flag)line.insert(i);
    }

    //縦に観て無視する行を決める
    for (int i = 0; i < W; i++) {
        bool bel_flag = true;
        for (int j = 0; j < H; j++) {
            if (a[j][i] == 1) {
                bel_flag = false;
                break;
            }
        }
        if (bel_flag)row.insert(i);
    }

    //答え出力
    for (int i = 0; i < H; i++) {
        if (line.find(i) != line.end())continue;
        for (int j = 0; j < W; j++) {
            if (row.find(j) != row.end())continue;
            cout << ((a[i][j]) ? "#" : ".");
        }
        cout << endl;
    }

    return 0;
}