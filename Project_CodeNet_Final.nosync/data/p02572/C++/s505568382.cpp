#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const ll mod=1000000007;

int main() {
  ll N;cin>>N;
  vector<int> A(N);rep(i,N) cin>>A[i];
  vector<ll> B(N+1,0);
  for(int i=0;i<N;i++){
    B[i+1]=B[i]+A[i];
  }
  
  ll sum=0;
  for(int i=0;i<N-1;i++){
    sum+=A[i]*((B[N]-B[i+1])%mod);
    sum%=mod;
  }
  
  cout << sum << endl;
}
