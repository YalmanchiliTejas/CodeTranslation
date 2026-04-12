#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};

vector<vector<ll>> dp(3500,vector<ll> (3500,0));
bool flag[3500][3500];
ll n;
vector<ll> a(3300);
ll dfs(ll l,ll r){
    if(l==r) {
        flag[l][r] = 1;
        return dp[l][r] = 0;
    }
    if(flag[l][r] == 1) return dp[l][r];
    flag[l][r] = 1;
    if((n-r+l)%2==0) dp[l][r] = max(dfs(l+1,r) + a[l],dfs(l,r-1) + a[r-1]);
    else dp[l][r] = min(dfs(l+1,r) - a[l],dfs(l,r-1) - a[r-1]);
    return dp[l][r];
    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    rep(i,n){
        cin >> a[i];
    }
    ll ans = dfs(0,n);
    cout << ans << endl;
    
    cout << endl;
    return 0;
}
