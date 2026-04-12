#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
 
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

int main(){
    ll h, w;
    cin >> h >> w;
    vvll a(h, vll(w));
    char c;
    REP(i, h){
        REP(j, w){
            cin >> c;
            if(c == '#') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    ll flg = 0;
    REP(i, h - 1){
        REP(j, w - 1){
            if(a[i][j] && a[i + 1][j] && a[i][j + 1]){
                flg = 1;
                break;
            }
        }
        if(flg) break;
    }
    REP(i, w - 2){
        if(a[h - 1][i] && a[h - 2][i + 1] && a[h - 1][i + 1] && a[h - 1][i + 2]){
            flg = 1;
            break;
        }
    }
    REP(i, h - 2){
        if(a[i][w - 1] && a[i + 1][w - 2] && a[i + 1][w - 1] && a[i + 2][w - 1]){
            flg = 1;
            break;
        }
    }
    if(a[h - 1][w - 2] && a[h - 2][w - 1]) flg = 1;
    if(flg) cout << "Impossible" << endl;
    else cout << "Possible" << endl;
    return 0;
}