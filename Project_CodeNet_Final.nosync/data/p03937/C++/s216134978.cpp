#include <bits/stdc++.h>
using namespace std;
using LL  = long long;
using VI  = vector<LL>;
using VVI = vector<VI>;
using VB  = vector<bool>;
using VS  = vector<string>;
using PII = pair<LL, LL>;
using VP  = vector<PII>;
#define PB           push_back
#define MP           make_pair
#define SZ(a)        LL((a).size())
#define EACH(x, c)   for (auto x : (c))
#define ALL(c)       (c).begin(), (c).end()
#define REVERSE(c)   reverse(ALL(c))
#define SORT(c)      stable_sort(ALL(c))
#define RSORT(c)     stable_sort((c).rbegin(), (c).rend())
#define FSORT(c)     stable_sort(ALL(c), [] (auto& x, auto& y) {return x.first < y.first;});
#define FRSORT(c)    stable_sort(ALL(c), [] (auto& x, auto& y) {return x.first > y.first;});
#define SSORT(c)     stable_sort(ALL(c), [] (auto& x, auto& y) {return x.second < y.second;});
#define SRSORT(c)    stable_sort(ALL(c), [] (auto& x, auto& y) {return x.second > y.second;});
#define FOR(i, a, b) for (LL i = (a); i < (b); ++i)
#define REP(i, n)    FOR(i, 0, n)
#define DEBUG true
#define $(x) {if (DEBUG) {cout << #x << " = " << (x) << endl;}}

vector<PII> directions{MP(1, 0), MP(0, 1)};

int main() {
    LL H, W;
    cin >> H >> W;
    vector<vector<char>> A(H, vector<char>(W));
    REP(i, H) {
        REP(j, W) {
            cin >> A[i][j];
        }
    }
    LL h = 0, w = 0;
    while (h < H || w < W) {
        int ndir = 0, nbdir = 0;
        if (h + 1 < H && A[h + 1][w] == '#') ndir++;
        if (w + 1 < W && A[h][w + 1] == '#') ndir++;
        if (h - 1 >= 0 && A[h - 1][w] == '#') nbdir++;
        if (w - 1 >= 0 && A[h][w - 1] == '#') nbdir++;
        if (((h != H - 1 || w != W - 1) && ndir != 1) || ((h > 0 || w > 0) && nbdir != 1)) {
            cout << "Impossible" << endl;
            return 0;
        }
        if (h == H - 1 && w == W - 1) {
            cout << "Possible" << endl;
            return 0;
        }
        if (h + 1 < H && A[h + 1][w] == '#') h++;
        else w++;
    }
    cout << "Impossible" << endl;
	
    return 0;
}
