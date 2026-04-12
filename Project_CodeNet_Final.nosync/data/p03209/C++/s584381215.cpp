#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using ll = long long;
using P = pair<int, int>;
#define debug(var) cout << "[" << #var << "] " << var << endl
const ll mod = 1000000007;

ll level[55];
ll paty[55];

ll f(ll n, ll x) {
    if (x==0) return 0;
    if (x==level[n]) return paty[n];
    if (n==0) {
        if (x==1) return 1;
        else return -1;
    }
    if (x<=level[n-1]+1) {
        return f(n-1, x-1);
    }
    else {
        return 1LL + paty[n-1] + f(n-1, x-2-level[n-1]);
    }
}

int main(){
    ll n, x;
    cin >> n >> x;
    ll ans = 0;
    for (int i=0; i<=51; i++) {
        if (i==0) {
            level[i] = 1;
            paty[i] = 1;
            continue;
        }
        level[i] = level[i-1] * 2 + 3;
        paty[i] = paty[i-1] * 2 + 1;
    }
    ans = f(n, x);
    
    
    
    cout << ans << endl;
    return 0;
}
