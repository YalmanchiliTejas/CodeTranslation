#include<iostream>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
int n;
int a[3005];
ll memo[3005][3005];

ll dp(int l,int r){
  if(l==r)return a[l];
  if(memo[l][r]!=-1)return memo[l][r];

  return memo[l][r]=max(a[l]-dp(l+1,r),-dp(l,r-1)+a[r]);
}
  
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  memset(memo,-1,sizeof(memo));
  
  cout<<dp(0,n-1)<<"\n";
  
  return 0;
}
  
