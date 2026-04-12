#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
typedef vector<vector<P>> vvP;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;

int main() {
    ll h, w;
    cin >> h >> w;

    vector<string> board(h);
    rep(i, h) {
        cin >> board[i];
    }

    vvl matrix(h, vl(w));
    rep(i, h) {
        ll ok = 1;
        rep(j, w) {
            if(board[i][j] == '#') {
                ok = 0;
            }
        }
        if(ok) {
            rep(j, w) {
                matrix[i][j] = 1;
            }
        }
    }

    rep(j, w) {
        ll ok = 1;
        rep(i, h) {
            if(board[i][j] == '#') {
                ok = 0;
            }
        }
        if(ok) {
            rep(i, h) {
                matrix[i][j] = 1;
            }
        }
    }

    rep(i, h) {
        ll ok = 0;
        rep(j, w) {
            if(!matrix[i][j]) {
                cout << board[i][j];
                ok = 1;
            }
        }
        if(ok || i == h-1) {
            cout << "\n";
        }
    }

    re0;
}