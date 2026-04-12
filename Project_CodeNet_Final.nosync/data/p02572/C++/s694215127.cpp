#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep1n(i,n) for(int i=1; i<=(n); ++i)
#define repxn(i,x,n) for(int i=x; i<=(n); ++i)
#define sort_u(x) sort((x).begin(),(x).end())
#define sort_d(x) sort((x).begin(),(x).end(), greater<int>())
#define pb push_back
#define INF 1001001001  // 浮動小数点型
#define INF_L 1001001001001001001  // 浮動小数点型
#define bit(n,m)(((n)>>(m))&1)  // nのmビット目が1
#define MOD 1000000007
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main() {
    ll n; cin >> n;
    vector<ll> a(n); rep(i, n) cin >> a[i];
    vector<ll> sum(n,0);
    sum[0] = a[0];
    rep(i,n){
        if(i == 0) continue;
        sum[i] = a[i] + sum[i-1];
    }
    ll ans = 0;
    for (ll i = 0; i < n-1; i++){
        ll s = (sum[n-1] - sum[i]) % MOD;
        ans += a[i] % MOD * s % MOD;
        ans %= MOD;
    }
    cout << ans << endl;       
}

/*
g++ c.cpp
./a.out
./problem.exe
oj d
oj t

debug:ctrl+shift+B problemin

*/
