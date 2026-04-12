#include<bits/stdc++.h>
using namespace std;


int n;
long long  dp[3100][3100];
long long  a[3100];
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
  cin>>n;
 for(int i=1;i<=n;i++)
 {
 	cin>>a[i];
 }
 
 for(int r=1;r<=n;r++)
 {
    for(int l=r;l>=1;l--){
      dp[r][l]=max(a[l]-dp[r][l+1],a[r]-dp[r-1][l]);
    }
 }
   
  
 
  cout<<dp[n][1]<<endl;
 
}