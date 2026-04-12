#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define mex 1000005
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
vector<int> adj[mex];
//a+b=a^b+2*(a&b)

long long recur(long long int a[], long long **dp, int i1, int i2){
	if(i1>i2)
	 return 0;
	if(dp[i1][i2]!=-1)
	 return dp[i1][i2];
	else{
		dp[i1][i2]=max((a[i1]-recur(a,dp,i1+1,i2)),(a[i2]-recur(a,dp,i1,i2-1)));
		return dp[i1][i2];
	}
}  
int main(){
	fast
	int n;
	cin>>n;
	long long int a[n];
	for(int i=0;i<n;i++)
	 cin>>a[i];
	long long ** dp;
	dp=new long long*[n+1];
	for(int i=0;i<=n;i++)
	 dp[i]=new long long[n+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++)
		 dp[i][j]=-1;
	} 
	cout<<recur(a,dp,0,n-1)<<endl;
}
