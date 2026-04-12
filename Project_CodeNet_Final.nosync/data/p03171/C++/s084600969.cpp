// correcting previous top down approach
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
double pi = acos(-1.0);
const double EPS=1e-9;
#define MOD ll(1e9L+7)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define t() ll tt;cin>>tt;while(tt--) 
#define t2() ll tt2; cin>>tt2; for(ll tti=1;tti<=tt2;tti++)
#define printcj "Case #"<<tti<<": "
#define debug1(x) cerr << #x << " = " << x << '\n';
#define debug2(x, y) cout << #x << " = " << x << "   " << #y << " = " << y << "\n";

const ll sz=3001,INF=-1e16L;
ll n,a[sz];
ll dp[sz][sz];


ll solve(ll i,ll j,bool xturn)
{
    if(i==j){
        if(xturn) return a[i];
        else return -a[i];
    }
    if(dp[i][j]!=INF) return dp[i][j];
    ll diff1 = solve(i+1,j,!xturn);
    ll diff2 = solve(i,j-1,!xturn);
    if(xturn) {
        if(diff1+a[i]>diff2+a[j]) return dp[i][j]=diff1+a[i];
        else return dp[i][j]=diff2+a[j];
    }
    else{
        if(diff1-a[i]<diff2-a[j]) return dp[i][j]=diff1-a[i];
        else return dp[i][j]=diff2-a[j];
    }

}

int main()
{
    fastio;
    ll i,j;
    cin>>n;
    for(i=0;i<n;i++)for(j=0;j<n;j++) dp[i][j] = INF;
    for(i=0;i<n;i++)cin>>a[i];
    
    ll diff = solve(0,n-1,1);
    cout<<diff;

    
}