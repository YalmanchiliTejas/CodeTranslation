#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long N;cin>>N;
  vector<long> A(N+10);
  for(int i=1;i<=N;i++)cin>>A[i];
  long mod=1000000007;
  long sum=0;
  long ruiwa=0;
  for(int i=N-1;i>=1;i--){
    ruiwa=(ruiwa+A[i+1])%mod;
    sum=(sum+(A[i]*ruiwa)%mod)%mod;
  }
  cout<<sum<<endl;
}
