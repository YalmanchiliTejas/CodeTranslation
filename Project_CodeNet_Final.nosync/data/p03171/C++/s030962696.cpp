#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define F first
#define S second
//cout<<fixed<<setprecision(11);
const string nl="\n";
const ll MOD=1e9+7;
const ll ARR_MAX = 3e3+1;
const ll INF=1e14;

ll dp[ARR_MAX][ARR_MAX]; //dp[i][j] = maximum value of X-Y when a[i ... j] is left.

void solve(){	
    int n;cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }
    for(int i=0;i<n;i++){
    	dp[i][i]=a[i];
    }
    int i=0;
    for(int d=1;d<n;d++){
    	for(i=0;i+d<n;i++){
    		dp[i][i+d]=max(a[i]-dp[i+1][i+d],a[i+d]-dp[i][i+d-1]);
    	}
    }
    cout<<dp[0][n-1]<<nl;
}

int main(){
    fastio();
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}