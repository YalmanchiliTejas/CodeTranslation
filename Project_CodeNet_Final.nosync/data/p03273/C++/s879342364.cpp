#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int H, W;
    cin >> H >> W;
    vector<string>masu(H);
    for (int i=0; i<H; i++) {
        cin >> masu.at(i);
    }

    vector<bool> gyou_assyuku(H, false);
    vector<bool> retsu_assyuku(W, false);
    for (int i=0; i<H; i++) {
        bool is_gyou_assyuku = true;
        for (int j=0; j<W; j++) {
            if (masu[i][j] == '#') {
                is_gyou_assyuku = false;
            }
        }

        if (is_gyou_assyuku) {
            gyou_assyuku[i] = true;
        }
    }

    for (int i=0; i<W; i++) {
        bool is_retsu_assyuku = true;
        for (int j=0; j<H; j++) {
            if (masu[j][i] == '#') {
                is_retsu_assyuku = false;
            }
        }

        if (is_retsu_assyuku) {
            retsu_assyuku[i] = true;
        }
    }

    for (int i=0; i<H; i++) {
        if (gyou_assyuku[i]) {
            continue;
        }

        for (int j=0; j<W; j++) {
            if (retsu_assyuku[j]) {
                continue;
            }

            cout << masu[i][j];
        }

        cout << endl;
    }
    return 0;
}