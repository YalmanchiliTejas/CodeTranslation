#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main() {
  ll N,X,M,i;
  cin>>N>>X>>M;
  vector<ll> idx(M,-1), a(M);
  ll x = X, len=0;
  while(idx[x] == -1) {
    idx[x] = len;
    a[len] = x;
    len++;
    x = x*x%M;
  }

  ll ans = 0;
  if (N<=len) {
    for (i=0;i<N;i++) ans += a[i];
  } else {
    for (i=0;i<len;i++) ans += a[i];
    N -= len;
    ll cycLen = len - idx[x];
    ll cycSum = 0;
    for (i=idx[x];i<len;i++) cycSum += a[i];
    ans += (N / cycLen) * cycSum;
    for (i=idx[x];i<idx[x]+(N % cycLen);i++) ans += a[i];
  }
  cout<<ans<<endl;
  return 0;
}
