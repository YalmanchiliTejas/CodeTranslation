#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll all[55],ap[55];
ll solve(int n,ll x);

int main(void){
  int n;
  ll x,ans;
  cin >> n >> x;
  all[0]=ap[0]=1;
  for (int i=1;i<=n;i++){
    all[i]=all[i-1]*2+3;
    ap[i]=ap[i-1]*2+1;
  }
  ans=solve(n,x);
  cout << ans << endl;
  return 0;
}

ll solve(int n,ll x){
  if (n==0) return x;
  if (x<=n) return 0;
  if (x==all[n]) return ap[n];
  if (x<=all[n-1]+1) return solve(n-1,x-1);
  if (x==all[n-1]+2) return ap[n-1]+1;
  return ap[n-1]+solve(n-1,x-all[n-1]-2)+1;
}