#include<bits/stdc++.h>
using namespace std;
const int N = 3030;
#define ll long long
ll dp[N][N];
ll a[N];
int n;
int main(){
  cin>>n;
  ll sum = 0;
  for(int i=0;i<n;++i){
    cin>>a[i];
    sum += a[i];
  }
  for(int gap = 0;gap<n;++gap){
    for(int i=0,j=gap;j<n;++i,++j){
      ll x = ((i+2<=j)?dp[i+2][j]:0);
      ll y = ((j-2>=i)?dp[i][j-2]:0);
      ll z = ((i+1<=j-1)?dp[i+1][j-1]:0);
      dp[i][j] = max(a[i]+min(x,z),a[j]+min(y,z));
    }
  }
  ll ans = dp[0][n-1];
  ll fans = 2*ans - sum;
  cout<<fans<<endl;
  return 0;
}