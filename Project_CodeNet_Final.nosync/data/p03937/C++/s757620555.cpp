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
    char c;
    ll res = 0;
    REP(i, h){
        REP(j, w){
            cin >> c;
            if(c == '#') res++;
        }
    }
    if(res == h + w - 1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}