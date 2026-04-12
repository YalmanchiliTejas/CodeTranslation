#include<iostream> 
#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
int main(){ 
	ios::sync_with_stdio(false); 
	cin.tie(0); 
	int N;
	cin>>N;
	vector<int> a(N);
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	vector<vector<ll>> dp(N,vector<ll>(N,0LL));
	int sign=N%2?-1:1;
        for(int i=0;i<N;i++){ 
		dp[i][i]=sign*a[i];
	} 
	bool turn=N%2?true:false; 

	for(int i=1;i<N;i++){
		turn=not turn;
		for(int j=0;j<N-i;j++){ 
			dp[j][j+i]=turn?min(dp[j+1][j+i]-a[j],dp[j][j+i-1]-a[j+i]):max(dp[j+1][j+i]+a[j],dp[j][j+i-1]+a[j+i]); 
		} 
	}
	cout<<-dp[0][N-1]; 


	
	return 0;
} 

