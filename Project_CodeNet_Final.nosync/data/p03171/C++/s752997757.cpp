#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll          long long
#define pb          push_back
#define mp 	    make_pair
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define vii         vector<pii>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define all(a)      (a).begin(),(a).end()
#define fi          first
#define si          second
#define sz(x)       (ll)x.size()
#define endl        '\n'
#define mod        1000000007
#define mset(m,v) memset(m,v,sizeof(m))
using namespace std;
ll power(ll a , ll b,ll modi)
{
    a%=modi;
    ll res = 1 ;
    while(b)
    {
        if(b%2) {
            res = (res * a) % modi ;
        }
        b/=2 ;
        a = (a*a) % modi ;
    }
    return res ;
}
//ll a[100001];
//ll a[200001];
ll dp[3000][3000];
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int t=1;
	//cin>>t;
	while(t--)
	{
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++)
	cin>>a[i];
	for(ll i=n-1;i>=0;i--){
		for(ll j=i;j<n;j++){
			int chance=n-(j-i);
			if(chance%2){
				if(i==j){
					dp[i][j]=a[i];
				}
				else{
					dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j]);
				}
			}
			else{
				if(i==j){
					dp[i][j]=-1*a[i];
				}
				else{
					dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j]);
				}
			}
		}
	}
	// for(ll i=0;i<n;i++){
		// for(ll j=0;j<n;j++)
		// cout<<dp[i][j]<<" ";
		// cout<<endl;
	// }
	cout<<dp[0][n-1];
	}
return 0;
}