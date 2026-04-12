/* Akshat Sharma @akshat98 */
#include <iostream>
#include <bits/stdc++.h>
#define IOS  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define mp   make_pair
#define pb   push_back
#define F    first
#define S    second
#define ll   long long
#define MOD  1000000007
#define MAX  1000000001
#define vi   vector<int>
#define vl   vector<ll>
#define vpi  vector<pair<int,int> >
#define vpl  vector<pair<ll,ll> >
#define rep(i,a,b) for(i=a;i<b;i++)
#define reqp(i,a,b) for(i=a;i<=b;i++)
#define ren for(i=0;i<n;i++)
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;


int main()
{

	ll i,j,k,l,n,test_case,m,r;
	test_case=1;
	//cin>>test_case;
	while(test_case--){
		cin>>n;
		ll dp[n+1][4];

		rep(i,0,n){
			rep(j,0,4){
				dp[i][j]=LLONG_MIN/100000;
			}
		}
		vl vec(n);
		ren cin>>vec[i];
		
		dp[0][0]=vec[0];
		dp[1][1]=vec[1];
		dp[2][0]=vec[0]+vec[2];
		dp[2][2]=vec[2];
		rep(i,3,n){
			dp[i][0]=vec[i]+dp[i-2][0];
			dp[i][1]=max(vec[i]+dp[i-3][0],vec[i]+dp[i-2][1]);
			dp[i][2]=(max(vec[i]+dp[i-2][2],vec[i]+dp[i-3][1]));
			if(i>=4)
			dp[i][2]=max(dp[i][2],vec[i]+dp[i-4][0]);
		}
		ll ans=LLONG_MIN;
		if(n&1){
			ans=max(ans,dp[n-1][2]);
			ans=max(ans,dp[n-2][1]);
			ans=max(ans,dp[n-3][0]);
		}else{
			ans=max(ans,dp[n-1][1]);
			ans=max(ans,dp[n-2][0]);
		}
		cout<<ans<<"\n";



	}
	
	return 0;
}
