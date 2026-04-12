#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const ll p=1000000007;
ll m[51];
ll o[51];
ll solve(ll n,ll k){
  if(k==0)return 0;
  if(k==m[n]||(k==m[n]-1&&n!=0))return o[n];
  if(k==1&&n==0)return 1;
  if(k==1)return 0;
  if(k*2+1==m[n])return o[n-1];
  if(k*2-1==m[n])return 1+o[n-1];
  if(k*2+1<m[n])return solve(n-1,k-1);
  return o[n-1]+1+solve(n-1,k-2-m[n-1]);
}
int main(){
  ll n,k;
  cin >> n >> k;
  o[0]=1;
  rep(i,50)o[i+1]=o[i]*2+1;
  m[0]=1;
  rep(i,50)m[i+1]=m[i]*2+3;
  cout << solve(n,k) << endl;
}
