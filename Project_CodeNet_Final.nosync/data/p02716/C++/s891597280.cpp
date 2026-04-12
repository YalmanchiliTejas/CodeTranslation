#include <bits/stdc++.h> 
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define maxnkp make_pair
#define fi first
#define se second
#define eps 1e-10
using namespace std;
typedef long long ll;
const int mods = 1e9+7;
const int maxn = 2e5+10;
const int N = 1e5+10;
const int E = 2e5+10;  
ll n,k;
ll a[maxn];
ll dp[maxn][3][2];

int main(){
	cin>>n;
	F(i,1,n) cin>>a[i];
	ll ans = -infll ;
	if(n%2==0){
		dp[1][0][0] = a[1];
		dp[1][1][0] = a[2]; 
		F(i,3,n){
			dp[i][0][0] = dp[i-2][0][0]+a[i];
			dp[i][1][0] = max(dp[i-2][0][0],dp[i-2][1][0])+a[i+1];
			i++;
		}
		ans = max(dp[n-1][0][0],dp[n-1][1][0]);
		cout<<ans<<endl;
	}
	else{
		if(n==3){
			F(i,1,n){
				ans = max(ans,a[i]);
			}
			cout<<ans<<endl;
			return 0;
		}
		dp[1][0][0] = a[1];
		dp[1][1][0] = a[2];
		dp[1][2][1] = a[3];
		F(i,3,n-1){
			dp[i][0][0] = dp[i-2][0][0]+a[i];
			dp[i][1][0] = max(dp[i-2][0][0],dp[i-2][1][0])+a[i+1];
			if(i<n-1) dp[i][2][1] = max(dp[i-2][0][0],dp[i-2][1][0])+a[i+2];
			dp[i][0][1] = max(dp[i-2][2][1],dp[i-2][0][1]+a[i]);
			dp[i][1][1] = max(dp[i-2][0][1],dp[i-2][1][1])+a[i+1];
			i++;
		}
		//cout<<dp[n-2][1][1]<<" "<<dp[n-2][2][1]<<" "<<dp[n-2][0][1]<<" "<<endl;
		ans = max(dp[n-2][0][1]+a[n],dp[n-2][2][1]);
		ans = max(dp[n-2][0][0],ans);
		ans = max(dp[n-2][1][0],ans);
		cout<<ans<<endl;
	}	
}