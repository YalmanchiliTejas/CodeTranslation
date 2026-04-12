#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)
const ll INF = (1LL<<60);
const int MOD = 1000000007;
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

int n;
vector<int> a(3030);
vector<vector<ll> > dp(3030,vector<ll>(3030,0));
bool seen[3030][3030];

// [l, r)
ll rec(int l, int r){
    if(l>r) return 0;
    if(seen[l][r]) return dp[l][r];

    seen[l][r] = true;

    ll res = 0;
    int dif = n-(r-l+1);
    if(dif%2==0){
        res = -INF;
        chmax(res, rec(l+1,r) + a[l]);
        chmax(res, rec(l,r-1) + a[r]);
    }else{
        res = INF;
        chmin(res, rec(l+1,r) - a[l]);
        chmin(res, rec(l,r-1) - a[r]);
    }

    return dp[l][r]=res;
}

int main(){
    cin >> n;
    rep(i,n) cin >> a[i];
    rec(0,n-1);
    cout << dp[0][n-1] << endl;
}