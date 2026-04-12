#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxs = 2e5+5;
const ll lmaxs = 20;
ll mod = 1e9+7;
ll oo = 1e15;

#define IOS ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define I insert
#define endl '\n'

void pre(){
    
}

ll dp[maxs];
ll pr[maxs];

void solve(){    
    ll n;
    cin >> n;
    ll a[n+1];
    for(ll i=1;i<n+1;i++)
        cin >> a[i];
    
    pr[1] = a[1];
    for(ll i=2;i<n+1;i++){
        pr[i] = pr[i-2] + a[i];
    }

    dp[0] = dp[1] = 0;
    for(ll i=2;i<n+1;i++){
        if(i&1){ // we have option to skip
            dp[i] = max(dp[i-1] , dp[i-2] + a[i]);
        }
        else{
            dp[i] = max(dp[i-2] + a[i] , pr[i-1]);            
        }
    }    
    cout << dp[n] << endl;
}

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input00.txt","r",stdin);
    // #endif
    IOS;
    pre();
    ll T = 1;   
    //cin>>T;
    while(T--){  
        solve();
    }
    return 0;
}