#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl "\n"
#define pii pair<int,int>
#define pll pair<ll,ll>
typedef long long ll;
#define loop() for(int i=0; i<(); i++)
const int MOD=1e9+7;
int modpow(int x, int n, int m)
{
    if(n==0) return 1;
    ll ans=1;
    while(n>0)
    {
        if(n%2==1) ans=(ans*x)%m;
        x=(x*x)%m;
        n/=2;
    }
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto&i :a) cin>>i;
    vector<vector<ll>>dp(n+1,vector<ll>(n+1,0));
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j>=1; j--)
        {
            if(j==i) dp[j][i]=a[i-1];
            else dp[j][i]=max(a[j-1]-dp[j+1][i],a[i-1]-dp[j][i-1]);
        }
    }
    cout<<dp[1][n]<<endl;
}   

int main(){
	fast
	int t=1;
	//cin>>t;
	while(t--) solve();

}
