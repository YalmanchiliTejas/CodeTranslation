#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,mod=1000000007;
  cin >> N;
  long long sum=0;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
    sum+=A.at(i);
  }
  long long ans=0;
  for(int i=0;i<N;i++){
    sum-=A.at(i);
    long long subsum=sum%mod;
    long long B=(A.at(i)*subsum)%mod;
    ans=(ans+B)%mod;
  }
  cout << ans << endl;
}
    
  