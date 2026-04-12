#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
typedef pair<ll,ll> pr;
typedef vector<ll> vc;
typedef unordered_map<ll,ll> umap;
#define pb emplace_back
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define reps(i,v) for(ll i=0;i<v.size();i++)
template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }
template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }
const ll mod = 1e9+7;

int main() {
    // your code goes here
    string k;
    ll n, d, pb, dp[105][10005]={0}, sum[1005]={0};
    cin >> k >> d;
    n = k.size();
    dp[0][0] = 1;
    rep(i,1,n){
    	pb = k[i-1] - '0';
    	sum[i] = (sum[i-1] + pb) % d;
    	rep(j,0,d-1) rep(k,0,9) dp[(j+k)%d][i] = (dp[(j+k)%d][i] + dp[j][i-1]) % mod;
    	rep(k,pb+1,9) dp[(sum[i-1]+k)%d][i] = (dp[(sum[i-1]+k)%d][i] - 1 + mod) % mod;
    }
    cout << (dp[0][n] - 1 + mod) % mod << endl;
    return 0;
}