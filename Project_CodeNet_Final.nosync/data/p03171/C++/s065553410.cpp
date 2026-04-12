#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<b;i++)
#define f(i,n) for(int i=0;i<n;i++)
typedef unsigned long long ull;
typedef long long ll;
#define vint vector<int>
#define vll vector<long long int>
#define pb(a) push_back(a);
#define bug(x) cout<<#x<<" = "<<x<<"\n";
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)

long long int dp[3002][3002];

// long long int func(int j,int i,vint a){
// 	// cout<<"called j="<<j<<" i="<<i<<"\n";
// 	if(i==j){return dp[j][i]=a[i];}
// 	else{
// 		// cout<<dp[j][i]<<" "<<INT_MIN<<"\n";
// 		if(dp[j][i]!=-1){return dp[j][i];}
// 		// cout<<"here\n";
// 		return dp[j][i] = max((long long int)a[j]-func(j-1,i,a),(long long int)a[i]-func(j,i+1,a));
// 	}
// 	return 0;
// }



int main(){
	fastio;
	int n; 
	cin>>n;
	vll a(n);
	f(i,n){cin>>a[i];}
	memset(dp,-1,sizeof(dp));
	

	// func(n-1,0,a);
	f(i,n){
		dp[i][i]=a[i];
	}
	for(int i=n-1;i>=0;i--){
		F(j,i,n){
			if(i==j){continue;}
			else{
				dp[i][j] = max(a[i]-dp[i+1][j],a[j] - dp[i][j-1]);
			}
		}
	}
	// cout<<dp[0][n-1]<<"\n";


	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	cout<<dp[0][n-1]<<"\n";
	return 0;
}