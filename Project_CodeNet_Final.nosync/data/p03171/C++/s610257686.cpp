#include<bits/stdc++.h>
#define ld long double
#define ll long long
ll dp[3005][3005];
using namespace std;

ll dequeue(ll a[],ll s,ll e){
	if(dp[s][e]!=-1){
		return dp[s][e];
	}
	if(s > e){
		return 0;
	}
	if(s == e){
		return a[s];
	}

	return dp[s][e] = max(dequeue(a,s,s) - dequeue(a,s+1,e) , dequeue(a,e,e) - dequeue(a,s,e-1));
	 
}

int main(){
	for(int i=0;i<3005;i++){
		for(int j = 0;j <= 3005;j++){
			dp[i][j] = -1;
		}
	}
	int n;
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
 	ll ans = 0;
 	int flag = 0;
	ans = dequeue(a,0,n-1);
	cout<<ans<<endl;
	// ll dp[N][2];
}