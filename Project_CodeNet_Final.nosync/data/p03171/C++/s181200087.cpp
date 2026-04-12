#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define F first
#define S second
#define vec vector
#define pb push_back
#define pll pair<ll,ll>
#define pdd pair<ld, ld>
#define pq priority_queue
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, int>
#define pnn pair<Node*, Node*>
#define uid uniform_int_distribution
#define FILE ifstream in("input.txt");ofstream out("output.txt");
#define fast cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);cout.sync_with_stdio(0);
using namespace std;
typedef string str;
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll a, inf = 1e18;
vec<ll> m, ps;
vec<vec<ll>> dp;

ll rec(ll l, ll r){
    if(dp[l][r]!=-inf) return dp[l][r];
    if(l==r) return dp[l][r] = m[l];
    return dp[l][r] = max((ps[r]-ps[l-1])-rec(l+1,r), (ps[r]-ps[l-1])-rec(l,r-1));
}

int main() {
    fast;
    cin>>a;
    m = vec<ll>(a+1);
    ps = vec<ll>(a+1);
    for(int q=1; q<=a; q++){
        cin>>m[q];
        ps[q] = m[q] + (q ? ps[q-1] : 0);
    }
    dp = vec<vec<ll>>(a+1, vec<ll>(a+1, -inf));
    ll X = rec(1, a);
   // cout<<X<<endl;
    cout<<2*X-ps[a];
}