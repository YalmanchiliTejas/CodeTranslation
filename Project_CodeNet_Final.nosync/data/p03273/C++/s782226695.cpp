#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<int> > field(h, vector<int>(w, 0));
    char c;
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) {
        cin >> c;
        if (c == '.') field[i][j] = 1;
    }

    vector<vector<int> > isWhite(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++) {
        bool is = true;
        for (int j = 0; j < w; j++) {
            if (field[i][j] == 0) is = false;
        }
        if (is) for (int j = 0; j < w; j++) isWhite[i][j] = 1;
    }
    for (int i = 0; i < w; i++) {
        bool is = true;
        for (int j = 0; j < h; j++) {
            if (field[j][i] == 0) is = false;
        }
        if (is) for (int j = 0; j < h; j++) isWhite[j][i] = 1;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (isWhite[i][j]) continue;
            if (field[i][j]) cout << '.';
            else cout << '#';
        }
        if (accumulate(isWhite[i].begin(), isWhite[i].end(), 0) != w) cout << '\n';
    }
}
