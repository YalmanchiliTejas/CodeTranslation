#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

ll pow(ll a, ll b, ll m)
{
    ll  ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}



int main()
{
	IOS;
	int t=1; //cin>>t;
	while(t--){
	    int n; cin>>n;
	    int a[n];
	    ll dp[n][n];
	    for(int i=0;i<n;i++){ cin>>a[i]; dp[i][i]=a[i];}
	    
	    for(int i=n-1;i>=0;i--) {
		  for(int j=i+1;j<n;j++) 
		  {
			dp[i][j] = max(a[i] - dp[i+1][j],a[j] - dp[i][j-1]);
		  }
	    }
 
	     cout<<dp[0][n-1];
	    
	    cout<<endl;
	}  
}