#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    ll h, w; cin >> h >> w;
    vector<string> board(h);
    map<int, int> h_whites;
    map<int, int> w_whites;
    for (int i = 0; i < h; ++i) {
        cin >> board[i];
        bool flag = true;
        for (int j = 0; j < w; ++j) {
            if (board[i][j] != '.') {
                flag = false;
                break;
            }
        }
        if (flag) h_whites[i] = 1;
    }
    for (int j = 0; j < w; ++j) {
        bool flag = true;
        for (int i = 0; i < h; ++i) {
            if (board[i][j] != '.') {
                flag = false;
                break;
            }
        }
        if (flag) w_whites[j] = 1;
    }

    // output
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (h_whites.count(i) || w_whites.count(j)) continue;
            cout << board[i][j];
        }
        if (!h_whites.count(i)) {
            cout << endl;
        }
    }
}