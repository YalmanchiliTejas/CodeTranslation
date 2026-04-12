#include <bits/stdc++.h>
#define rep(i, n) for(ll i=0; i<(n); ++i)
#define rep1(i,n) for(ll i=1; i<=(n); ++i)
#define repi(i,a,b) for(ll i=a; i<=(b); ++i)
#define rrep(i,n) for(ll i=(n-1); i>=0; --i)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define pb push_back
#define mp make_pair
#define to_s to_string
#define sz(v) (int)v.size()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )
#define print(x) cout<<(x)<<'\n'
#define debug(x) cout << #x << ": " << (x) << '\n'
using namespace std;
using ll = long long;
using Edge = pair<ll,ll>;
using Graph = vector<vector<Edge>>;
typedef pair<ll,ll> P;
struct aaa{aaa(){ cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);};}aaaaaaa;
ll MOD = 1e9 + 7;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
ll devc(ll x, ll y){return 1 + (x-1)/y;}
ll modpow(ll x, ll y, ll m) {
    if (y == 0) return 1;
    ll res = modpow(x, y / 2, m);
    return res * res % m * (y & 1 ? x : 1) % m;
}
ll modinv(ll x) { return modpow(x, MOD - 2, MOD); }

int main(){
    string N; ll K; cin >> N >> K;
    
    vector<ll> n; 
    for(auto s : N) n.pb(s-'0');
    ll l = sz(n);
    ll dp[150][2][5];
    
    dp[0][0][0] = 1;
    
    for(int i = 0; i < l; i++){
        for(int smaller = 0; smaller < 2; smaller++){
            for(int j = 0; j <= 4; j++){
                for(int x = 0; x <= (smaller ? 9 : n[i]); x++){
                    dp[i + 1][smaller || x < n[i]][min(j + (x != 0), 4)] += dp[i][smaller][j];
                }
            }
        }
    }
    
    print(dp[l][0][K] + dp[l][1][K]);
    return 0;
}