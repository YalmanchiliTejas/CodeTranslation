#include <bits/stdc++.h>
using namespace std;
long long f[3005][3005],pre[3005][3005];
int a[3005];
const int mod=998244353;
int main() {
  int N,V;
  cin>>N>>V;
  for(int i=1;i<=N;i++) {
    cin>>a[i];
  }
  for(int i=1;i<=N;i++) {
	for(int j=1;j<=V;j++) {
      if(j==a[i]) {
        f[i][j]=i;
      }else {
        if(j>=a[i]) {
          f[i][j]=pre[i-1][j-a[i]]%mod;
        }
      }
      pre[i][j]=(pre[i-1][j]+f[i][j])%mod;
    }
  }
  long long ans=0;
  for(int i=1;i<=N;i++) {
    ans=(ans+(N-i+1)*f[i][V]%mod)%mod;
  }
  cout<<ans;
  return 0;
}