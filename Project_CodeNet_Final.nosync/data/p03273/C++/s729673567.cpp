#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W; // 1 <= H, W <= 100
    cin >> H >> W;
    vector<string> a(H);
    for (int i = 0; i < H; i++) {
        cin >> a.at(i);
    }
    // skipする行を確認する
    vector<bool> skip_H(H), skip_W(W);
    for (int i = 0; i < H; i++) {
        bool tf = true;
        for (int j = 0; j < W; j++) {
            if (a.at(i).at(j)=='#') {tf=false; break;}
        }
        skip_H.at(i) = tf;
    }
    // skipする列を確認する
    for (int j = 0; j < W; j++) {
        bool tf = true;
        for (int i = 0; i < H; i++) {
            if (a.at(i).at(j)=='#') {tf=false; break;}
        }
        skip_W.at(j) = tf;
    }
    for (int i = 0; i < H; i++) {
        if (skip_H.at(i)) {continue;}
        for (int j = 0; j < W; j++) {
            if (skip_W.at(j)) {continue;}
            cout << a.at(i).at(j);
        }
        cout << endl;
    }
}