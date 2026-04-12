#include<bits/stdc++.h>
using namespace std;
const int ms = 3e3+9;
long long int dp[ms][ms][2];
long long int arr[ms], n;

long long int solve(int l, int r, int player){
  if(l == r){
    if(player)
      return -arr[l];
    return arr[l];
  }

  long long int &ans = dp[l][r][player];
  if(~ans)
    return ans;

  if(player){
    ans = min( -arr[l] + solve(l+1, r, 0), -arr[r] + solve(l, r-1, 0));
  } else {
    ans = max(arr[l] + solve(l+1, r, 1), arr[r] + solve(l, r-1, 1));
  }

  return ans;
}



int main(){
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];

  int l = 0, r = n-1;

  memset(dp, -1, sizeof dp);
  cout<<solve(l, r, 0)<<endl;
}