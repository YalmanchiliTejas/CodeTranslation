//Link : https://codeforces.com/contest/1253

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200005
#define mod 998244353
/*
#include <limits.h>
INT_MAX
LLONG_MAX
*/
ll a[N];
ll odd[N],even[N];
void solve() {
  int n;
  scanf("%d ", &n);
  for(int i=1;i<=n;++i) {
    scanf("%lld  ", &a[i]);
  }
  for(int i=1;i+1<=n;i+=2) {
    if(i==1) {
      even[i] = a[i];
      even[i+1] = a[i+1];
    } else {
      even[i+1] = a[i+1] + even[i-1];
      even[i] = a[i] + even[i-2];
    }
    even[i+1] = max(even[i+1],even[i]);
  }
  for(int i=3;i<=n;i+=2) {
    odd[i] = max(even[i-1], a[i] + odd[i-2]);
  }
  if(n&1) {
    printf("%lld\n", odd[n]);
  } else {
    printf("%lld\n", even[n]);
  }
}

int main() {
    //freopen("input.txt","r",stdin);
    solve();
    return 0;
}
