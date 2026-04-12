#include<bits/stdc++.h>
using namespace std;


int main(){
  
  long long asum=0, sum=0, N, i;
  cin>>N;
  vector<long long> A(N);
  for(i=0; i<N; i++){
    cin>>A[i];
    asum+=A[i];
  }
  for(i=0; i<N; i++){
    
    asum-=A[i];
    sum+=(A[i]*(asum%1000000007))%1000000007;
  }
  cout<<sum%1000000007<<endl;
  return 0;
}
