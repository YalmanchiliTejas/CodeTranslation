// in the name of Allah

#include<bits/stdc++.h>
#define ll long long
#define int long long
#define F first
#define S second
#define MP make_pair
#define pii pair<int, int>
#define p push_back

using namespace std;

const ll mx=2e5+5;

ll n, x, dp[mx];
map<ll, ll>c;
int an(int a, int b){
	if(a==1){
		if(b>=1) return 1;
		else return 0;
	}
	if(b==a/2+1){
		return(1+an(a/2-1, a/2-1));
	}
	if(b<a/2+1){
		return(an(a/2-1, b-1));
	}
	if(b>a/2+1){
		return(c[a/2-1]+1+an(a/2-1, b-(a/2+1)));
	}	
}
int32_t main(){
	ios::sync_with_stdio(false);
	cin>>n>>x;
	dp[0]=1;
	c[1]=1;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]*2+3;
		c[dp[i]]=c[dp[i-1]]*2+1;
		//cout<<dp[i]<<" "<<c[dp[i]]<<endl;
	}	
//	cout<<an(5, 5)<<endl;
	cout<<an(dp[n], x)<<endl;
	//cout<<dp[n]<<endl;
	return 0;
}