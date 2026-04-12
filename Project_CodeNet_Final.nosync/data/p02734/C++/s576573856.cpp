#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxs = 1e6+5;
const ll lmaxs = 20;
ll mod = 1e9+7;
ll oo = 1e15;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define I insert

ll n,s;
ll dp[3005][3005];
ll a[maxs];

ll go(ll pos,ll s){
    if(s==0){
        return n-pos+1 + 1;
    }
    if(pos > n || s < 0)
        return 0;
    ll& ans = dp[pos][s];
    if(ans != -1)
        return ans;
    ans =0;
    ans = go(pos+1 , s-a[pos]) + go(pos+1,s);
    ans %= mod;
    return ans;
}

void solve(){
    mod = 998244353;
    memset(dp,-1,sizeof dp);
    cin>>n>>s;
    for(ll i=1;i<n+1;i++)
        cin>>a[i];
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ans += go(i,s);
        if(ans > mod )
            ans -= mod;
    }
    cout << ans ;
}

int main() {
    
    IOS;
    int T=1;
    //cin >> T;
    while(T --){
        solve();
    }
}