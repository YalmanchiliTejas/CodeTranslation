#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#include <map>
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using Graph = vector<vector<int>>;


template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
ll modinv(ll a, ll m){
    ll b = m, u = 1, v = 0;
    while(b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if(u < 0) u += m;
    //cout << u << endl;
    return u;
}

ll paty_counter(ll level, ll x){
    ll size = pow(2, level+2) - 3;
    ll pmi = pow(2, level) - 1;
    if(x == 0){
        return 0;
    }else if(level == 0){    
        return 1;
    }else{
        if(x <= (size - 1)/2){
            return paty_counter(level-1, x-1);
        }else{
            return pmi + 1 + paty_counter(level-1, x - pow(2, level+1) + 3 - 2);
        }
    }

}
 
using namespace std;
using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;
static ll x;
void dfs(const Graph &G, int v) {
    seen[v] = true;
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue;
        dfs(G, next_v); // 再帰的に探索
        x ++;
    }
}

ll fr(ll n){
    ll ans = 1;
    REP(i, n){
        ans *= i+1;
        ans %= MOD;
    }
    return ans;
}

ll conb(ll n, ll k){
    return fr(n)% MOD * modinv(fr(k) * fr(n-k) % MOD, MOD) % MOD;
}

int main() {
    ll x;
    cin >> x;
    if(x >= 30){
        cout << "Yes"<< endl;
    }else {
        cout << "No" << endl;
    }
}

