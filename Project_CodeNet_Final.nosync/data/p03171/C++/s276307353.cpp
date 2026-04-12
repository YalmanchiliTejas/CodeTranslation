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

const ll sz=3001;
ll n,a[sz];
ll dp[sz][sz];

int main()
{
    fastio;
    ll i,j;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];

    // dp[i][j] = optimal difference in [ a[i],a[i+1],........,a[j-1],a[j] ]
    for(i=n-1;i>=0;i--){
        dp[i][i] = (n%2!=0)? a[i] : -a[i]; 
        for(j=i+1;j<n;j++){
            // x turn
            if(n%2==(j-i+1)%2)
                dp[i][j] = max(dp[i+1][j]+a[i],dp[i][j-1]+a[j]);
            else
                dp[i][j] = min(dp[i+1][j]-a[i],dp[i][j-1]-a[j]);
        }
    }
    cout<<dp[0][n-1];    
    
}