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
    cout << u << endl;
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
 
int main() {
    ll n, x;
    cin >> n >> x;
    cout << fixed << paty_counter(n, x) << endl;
}

