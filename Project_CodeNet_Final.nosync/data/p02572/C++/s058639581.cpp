#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,i;
  cin >> N;
  int A[N];
  long long int sum=0,ans=0;
  long long int mod=1000000007;
  for(i=0;i<N;i++){
    cin >> A[i];
    sum+=A[i];
    sum%=mod;
  }
  
  for(i=0;i<N;i++){
    sum-=A[i];
    if(sum<0) sum+=mod;
    ans+=sum*A[i];
    ans%=mod;
  }
  cout << ans << endl;
  return 0;
}