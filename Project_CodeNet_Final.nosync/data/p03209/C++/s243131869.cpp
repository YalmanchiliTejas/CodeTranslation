#include <bits/stdc++.h>
template<class T> inline bool chmin(T&a, T b){if(a > b){a = b; return true;}else{return false;}}
template<class T> inline bool chmax(T&a, T b){if(a < b){a = b; return true;}else{return false;}}
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1.0)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

ll n, x;
vector<ll> a = {1}, b = {1};

ll solve(ll N, ll X){
    if(N == 0) return (X <= 0 ? 0 : 1);
    else if(X <= 1 + a[N-1]) return solve(N-1, X-1);
    else return 1 + b[N-1] + solve(N-1, X-2-a[N-1]);
}

int main() {
    cin >> n >> x;
    rep(i, n){
        a.push_back(a[i] * 2 + 3);
        b.push_back(b[i] * 2 + 1);
    }
    cout << solve(n, x) << endl;
}