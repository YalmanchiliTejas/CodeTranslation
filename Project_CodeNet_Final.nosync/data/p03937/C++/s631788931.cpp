#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
const long double PI = acos(-1.0L);
const long long MOD = 1000000007LL;
// const long long MOD = 998244353LL;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true;} return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true;} return false; }
///////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int H,W; cin >> H >> W;
    vector<vector<char>> A(H, vector<char>(W));
    rep(i,H) rep(j,W) cin >> A[i][j];

    vector<int> B(H+W-2,1);
    rep(i,H-1) B[i] = 0;
    do {
        vector<vector<char>> C(H, vector<char>(W,'.'));
        C[0][0] = '#';
        int x = 0;
        int y = 0;
        for (auto i : B) {
            if (i) {
                y++;
                C[x][y] = '#';
            } else {
                x++;
                C[x][y] = '#';
            } 
        }
        if (A == C) {
            cout << "Possible" << endl;
            return 0;
        }
    } while (next_permutation(all(B)));

    cout << "Impossible" << endl;
}