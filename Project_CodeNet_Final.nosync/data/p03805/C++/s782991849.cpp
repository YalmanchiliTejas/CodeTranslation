#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N, M;
bool adj[10][10];

signed main(){
    cin >> N >> M;
    ll a, b;
    REP(i, M){
        cin >> a >> b;
        a--; b--;
        adj[a][b] = adj[b][a] = true;
    }
    vector<ll> v(N);
    iota(ALL(v), 0);
    ll ans = 0;
    do{
        if(v[0] != 0) break;
        bool ok = true;
        REP(i, N - 1){
            if(!adj[v[i]][v[i + 1]]) ok = false;
        }
        ans += ok;
    }while(next_permutation(ALL(v)));
    PRINT(ans);
    return 0;
}