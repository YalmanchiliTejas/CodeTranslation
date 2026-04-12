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
    int H, W;
    cin >> H >> W;
    vector<string> v(H);
    for (int i = 0; i < H; i++) cin >> v[i];
    vector<int> delRow(H), delCol(W);

    bool isWhite;
    for (int i = 0; i < H; i++) {
        isWhite = true;
        for (int j = 0; j < W; j++) if (v[i][j] == '#') isWhite = false;
        if (isWhite) delRow[i] = 1;
    }
    for (int i = 0; i < W; i++) {
        isWhite = true;
        for (int j = 0; j < H; j++) if (v[j][i] == '#') isWhite = false;
        if (isWhite) delCol[i] = 1;
    }

    for (int i = 0; i < H; i++) {
        if (delRow[i]) continue;
        for (int j = 0; j < W; j++) if (!delCol[j]) cout << v[i][j];
        cout << '\n';
    }
}
