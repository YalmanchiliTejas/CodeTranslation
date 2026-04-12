#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[3001][3001] = {};
bool used[3001][3001] = {};
ll a[3001] = {};

ll solve(int l, int r, bool turn){
  if(l>r) return 0;
  if(used[l][r]) return dp[l][r];

  used[l][r] = true;
  ll ret;
  if(turn){
    ret = max(a[l] + solve(l+1, r, !turn), a[r] + solve(l, r-1, !turn));
  }else{
    ret = min(-a[l] + solve(l+1, r, !turn), -a[r] + solve(l, r-1, !turn));
  }
  dp[l][r] = ret;
  return dp[l][r];
}

int main(){
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> a[i];
  cout << solve(0, n-1, true) << endl;
}
