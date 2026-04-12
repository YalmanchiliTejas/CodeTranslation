#include "bits/stdc++.h"
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector <char>> a(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> a[i][j];
        }
    }
    
    vector<int> ansH(H);
    vector<int> ansW(W);
    for (int i = 0; i < H; i++) {
        ansH[i] = i;
    }
    for (int i = 0; i < W; i++) {
        ansW[i] = i;
    }

    for (int i = 0; i < H; i++) {
        bool flag = true;
        for (int j = 0; j < W; j++) {
            if (a[i][j] == '#') {
                flag = false;
            }
        }
        if (flag) {
            for (int k = 0; k < ansH.size(); k++) {
                if (ansH[k] == i) {
                    ansH.erase(ansH.begin() + k);
                    break;
                }
            }
        }
    }
    for (int j = 0; j < W; j++) {
        bool flag = true;
        for (int i = 0; i < H; i++) {
            if (a[i][j] == '#') {
                flag = false;
            }
        }
        if (flag) {
            for (int k = 0; k < ansW.size(); k++) {
                if (ansW[k] == j) {
                    ansW.erase(ansW.begin() + k);
                    break;
                }
            }
        }
    }

    for (int i = 0; i < ansH.size(); i++) {
        for (int j = 0; j < ansW.size(); j++) {
            cout << a[ansH[i]][ansW[j]];
        }
        cout << endl;
    }
}