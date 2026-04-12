#include <bits/stdc++.h>
using namespace std;
int main(){
  #define int long long
  int N,sum=0;
  cin>>N;
  int MOD=1000000007;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
    sum+=A.at(i);
    sum%=MOD;
  }
  int ans=0;
  for(int i=0;i<N-1;i++){
    sum-=A.at(i)-MOD;
    sum%=MOD;
    ans+=sum*A.at(i);
    ans%=MOD;
  }
  cout<<ans<<endl;
}