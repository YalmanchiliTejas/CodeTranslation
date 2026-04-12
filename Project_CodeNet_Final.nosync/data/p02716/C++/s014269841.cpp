//OPTIMIZATONS
#pragma GCC optimize("02")
//CODE
#include<bits/stdc++.h>
// uncomment the below code to use int as long long
#define int long long
// uncomment the below code to use float as double
//#define float double
#define endl "\n"
#define debug cout<<"Good uptill here"<<endl<<flush;
#define deb(x) cout<<#x<<":"<<x<<endl<<flush;

using namespace std;
const int inf = 9e18;
const int N = 2e5 + 1;
int n;
int arr[N];
int dp[N][3];

int func(int a,int b){
	if(a>=n){
		if(b<1 && n&1) return -inf;
		return 0;
	}
	if(dp[a][b]!=inf) return dp[a][b];
	if(n%2==0){ 
		if(b==1) dp[a][b] = func(a+2,b)+arr[a];
		else dp[a][b] = max(func(a+1,b+1),func(a+2,b)+arr[a]);
	}else{
		if(b==2) dp[a][b] = func(a+2,b)+arr[a];
		else dp[a][b] = max(func(a+1,b+1),func(a+2,b)+arr[a]);
	}
	return dp[a][b];
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	//CODE FOR SPECIFIED INPUT AND OUTPUT
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for(int i=0;i<N;i++)for(int j=0;j<3LL;j++) dp[i][j]=inf;
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	int ans = func(0,0);
	cout<<ans<<endl;
	return 0;
}

