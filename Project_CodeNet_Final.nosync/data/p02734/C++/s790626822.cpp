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

const int MAX = 3005;
ll dp[MAX][MAX];

void solve(){
    mod =  998244353;
    ll n,s;
    cin>>n>>s;
    ll ans=0;
    ll a[n+1];
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        memcpy(dp[i],dp[i-1] ,sizeof dp[0]);
        (dp[i][a[i]] += i)%=mod;
        for(ll j=0 ; j+a[i] <= s ; j++){
            (dp[i][j+a[i]] += dp[i-1][j])%= mod;
        }
        ans += dp[i][s];
        ans %= mod;
    }
    cout << ans << endl;
}

int main(){
   
    IOS;
    ll T = 1;
    //cin>>T;
    while(T--){
        solve();   
    }
    return 0;
}