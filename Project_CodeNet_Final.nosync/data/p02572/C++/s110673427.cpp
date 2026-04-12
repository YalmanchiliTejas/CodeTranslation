#include <bits/stdc++.h>
using namespace std; 
   
int main(){
  int N,mod=1000000007;
  cin >> N;
  long long sum=0,ans=0;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
    sum+=A.at(i);
  }
  for(int i=0;i<N;i++){
    sum-=A.at(i);
    long long B=sum%mod;
    long long add=(B*A.at(i))%mod;
    ans=(ans+add)%mod;
  }
  cout << ans << endl;
}