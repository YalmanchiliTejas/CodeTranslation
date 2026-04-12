#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rrep(i,n) for (int i = n-1; i >= 0; i--)
#define rep2(i,s,n) for (int i = s; i < n; ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define tmax(a,b,c) max(a,max(b,c))
#define tmin(a,b,c) min(a,min(b,c))
#define pb push_back
using namespace std;
using ll = long long;
using P = pair<int,int>;
using LP = pair<ll,ll>;
template<class T> inline bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;
const ll linf = 1001001001001001001;

ll width[51];
ll paty[51];

ll solve(ll n,ll x) {
    if(n == 0) return x;
    if(x <= 1) return 0;
    if(x >= width[n]) return paty[n];
    ll w = width[n];
    if(x <= w/2) return solve(n-1,x-1);
    return paty[n-1]+1+solve(n-1,x-w/2-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    width[0] = 1;
    rep(i,50) width[i+1] = width[i]*2+3;
    paty[0] = 1;
    rep(i,50) paty[i+1] = paty[i]*2+1;
    ll n,x;
    cin >> n >> x;
    cout << solve(n,x) << endl;
}