#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int H, W; cin >> H >> W;
    vector<vector<char>> a(H, vector<char>(W));
    for(int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> a.at(i).at(j);
        }
    }
    vector<bool> Hjudge(H, true), Wjudge(W, true);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (a.at(i).at(j) == '#') {
                Hjudge.at(i) = false;
            }
        }
    }
    for (int j = 0; j < W; j++) {
        for (int i = 0; i < H; i++) {
            if (a.at(i).at(j) == '#') {
                Wjudge.at(j) = false;
            }
        }
    }
    for (int i = 0; i < H; i++) {
        if (Hjudge.at(i) == false) {
            for (int j = 0; j < W; j++) {
                if (Wjudge.at(j) == false) {
                    cout << a.at(i).at(j);
                }
            }
            cout << endl;
        }
    }
    return 0;
}