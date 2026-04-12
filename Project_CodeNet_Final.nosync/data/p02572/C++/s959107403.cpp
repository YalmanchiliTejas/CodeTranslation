#include <bits/stdc++.h>
using namespace std;

int main(){
  const int64_t mod=1e9+7;
  int64_t N;
  cin >> N;
  int64_t sum=0;
  vector<int64_t> A(N);
  for(int64_t i=0;i<N;i++){
    cin >> A.at(i);
    sum+=A.at(i);
    sum%=mod;
  }
  int64_t ans=0;
  for(int64_t i=0;i<N-1;i++){
    sum-=A.at(i);
    if(sum<0){
      sum+=mod;
    }
    ans+=(sum*A.at(i))%mod;
    ans%=mod;
  }
  cout << ans << endl;
  return 0;
}
