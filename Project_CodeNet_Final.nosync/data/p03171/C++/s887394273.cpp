#include<iostream>
#include<algorithm>
using namespace std;
long long int dp[3000][3000];
long long int game(int b,int e,int chance,long long int a[]){
	if(e==b){
		if(chance%2)
		return 0;
		return a[e];
	}
	if(chance%2){
		long long int f=game(b+1,e,chance+1,a);
		long long int s=game(b,e-1,chance+1,a);
		if(f<s)
		return f;
		return s;
	}
	if(dp[b][e]==-1)
	dp[b][e]=max(game(b+1,e,chance+1,a)+a[b],game(b,e-1,chance+1,a)+a[e]);
	return dp[b][e];
}
int main(){
	int n;cin>>n;
	long long int sum=0,a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];sum=sum+a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		dp[i][j]=-1;
	}
	cout<<2*game(0,n-1,0,a)-sum;
}