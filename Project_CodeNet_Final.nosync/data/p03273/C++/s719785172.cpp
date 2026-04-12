#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

#define int long long
#define MOD7 1000000007
#define MOD9 1000000009

#define rep(i, n) for (int i = 0; i < (n); i++)
#define itrep(i, a) for (auto i = (a).begin(); i != (a).end(); i++)
#define REP(i, a, n) for (int i = (a); i <= (n); i++)
#define all(a) (a).begin(), (a).end()
#define mp(a, b) make_pair((a), (b))

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

template<class T> void inputVector(vector<T>& v, int n) {
    v.resize(n);
    for (int i = 0; i < v.size(); i++) cin >> v[i];
}

signed main() {
    int H, W;
    cin >> H >> W;

    vector<string> board;
    inputVector(board, H);

    bool h[110], w[110];

    rep(y, H) {
        h[y] = true;
        rep(x, W) {
            h[y] &= board[y][x] == '.';
        }
    }

    rep(x, W) {
        w[x] = true;
        rep(y, H) {
            w[x] &= board[y][x] == '.';
        }
    }

    rep(y, H) {
        if (h[y]) continue;
        rep(x, W) {
            if (w[x]) continue;
            cout << board[y][x];
        }
        cout << endl;
    }
}
