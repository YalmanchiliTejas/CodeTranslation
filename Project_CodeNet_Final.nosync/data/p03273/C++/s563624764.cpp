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
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
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

    vvl board(h, vl(w));
    rep(i, h) {
        string s;
        cin >> s;
        rep(j, w) {
            if(s[j] == '#') {
                board[i][j] = 1;
            }
        }
    }

    vvl v(h, vl(w));
    rep(i, h) {
        bool ok = false;
        rep(j, w) {
            if(board[i][j]) {
                ok = true;
            }
        }
        if(ok) {
            rep(j, w) {
                v[i][j] = board[i][j];
            }
        }
        else {
            rep(j, w) {
                v[i][j] = -1;
            }
        }
    }

    rep(j, w) {
        bool ok = false;
        rep(i, h) {
            if(v[i][j] == 1) {
                ok = true;
            }
        }
        if(ok) {
            rep(i, h) {
                if(v[i][j] != -1) {
                    v[i][j] = board[i][j];
                }
            }
        }
        else {
            rep(i, h) {
                v[i][j] = -1;
            }
        }
    }

    rep(i, h) {
        bool ok = false;
        rep(j, w) {
            if(v[i][j] != -1) {
                ok = true;
            }
        }
        if(ok) {
            rep(j, w) {
                if(v[i][j] == 0) {
                    cout << '.';
                }
                else if(v[i][j] == 1) {
                    cout << '#';
                }
            }
            cout << "\n";
        }
    }
    
    re0;
}