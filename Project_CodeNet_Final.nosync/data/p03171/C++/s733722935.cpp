#include<bits/stdc++.h>
using namespace std;
int n;
const long long INF=int(1e13);
vector<int> a;
vector< vector <long long > > dp;

long long solve(int i,int j,int player){
	if(i==j) return a[i];
	else if(dp[i][j]!=INF) return dp[i][j];
	else{
		dp[i][j]=max(a[i]-solve(i+1,j,-player),a[j]-solve(i,j-1,-player));
	}
	//cout<<i<<" " <<j<<" "<<dp[i][j]<<"\n";
	return dp[i][j];
	
}
int main(){
	cin>>n;
	a.assign(n,0);
	for(int i=0;i<n;i++) cin>>a[i];
	dp.assign(n,vector<long long> (n,INF));

	cout<<solve(0,n-1,1);
	return 0;

}




	







