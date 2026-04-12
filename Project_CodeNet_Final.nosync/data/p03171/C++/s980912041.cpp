#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[3001][3001];

ll solve(ll sum,ll arr[],ll start,ll end){
	if(start>end)
		return 0;
	if(start==end)
		return arr[start];
	if(dp[start][end]!=-1)
		return dp[start][end];
	
	ll op1=sum-solve(sum-arr[start],arr,start+1,end);
	ll op2=sum-solve(sum-arr[end],arr,start,end-1);
	dp[start][end]=max(op1,op2);
	return dp[start][end];
}

int main(){
	ll N;
	cin>>N;
	ll arr[N];
	ll sum=0;
	for(ll i=0;i<N;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	for(ll i=0;i<=N;i++){
		for(ll j=0;j<=N;j++){
			dp[i][j]=-1;
		}
	}
	cout<<2*solve(sum,arr,0,N-1)-sum<<endl;
	
}