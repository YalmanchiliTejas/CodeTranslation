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

    vvl board1(h, vl(w));
    rep(i, h) {
        string s;
        cin >> s;
        rep(j, w) {
            if(s[j] == '#') {
                board1[i][j] = 1;
            }
        }
    }

    vvl board2(h);
    rep(j, w) {
        bool ok = false;
        rep(i, h) {
            if(board1[i][j]) {
                ok = true;
            }
        }
        if(ok) {
            rep(i, h) {
                board2[i].pb(board1[i][j]);
            }
        }
    }    

    rep(i, h) {
        bool ok = false;
        rep(j, board2[i].size()) {
            if(board2[i][j]) {
                ok = true;
            }
        }
        if(ok) {
            rep(j, board2[i].size()) {
                if(board2[i][j]) {
                    cout << '#';
                }
                else {
                    cout << '.';
                }
            }
            cout << "\n";
        }
    }
    
    re0;
}