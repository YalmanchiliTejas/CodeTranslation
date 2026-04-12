#include <bits/stdc++.h>
const int M =998244353; 
#define int long long int
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define MAX 1e15+1
#define pi  pair<int,int>  
const int mod = 1e9 + 7;
const int N = 3e3 + 7;
 
int n,a[N],sum;
int dp[N][N][2];
int solve(int i,int j,int ch) {

	if(i>j||i>n-1||j<0){
		
		return 0;
	}
	if(dp[i][j][ch]!=-1)return dp[i][j][ch];
	
	int val;
	int x = solve(i,j-1,(ch+1)%2);
	int y = solve(i+1,j,(ch+1)%2);
	if(ch==0){
		x=x+a[j];
		y=y+a[i];
		 val=max(x,y);
		
	}
	else{
		
		 x -=a[j];
		 y -=a[i];
		 val=min(x,y);
		

	}
	dp[i][j][ch]=val;
	return val;
 
 
}
 
signed main() {
  fast;
  
  cin>>n;
  for(int i=0;i<n;i++){
  	cin>>a[i];
  }
  	
  	
  memset(dp,-1,sizeof(dp));
  cout<<solve(0,n-1,0);
  



  	
}