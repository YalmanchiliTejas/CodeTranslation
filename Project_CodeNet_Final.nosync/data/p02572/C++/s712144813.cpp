#include <bits/stdc++.h>
using namespace std;

long long  N;
long long  A[2*100000+1];
const long long mod=1000000000+7;
int main(){
  long long sum=0;
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  for(int i=0;i<N;i++){
    sum +=A[i];
  }
  sum %=mod;
  sum= (sum*sum)%mod;
  for(int i=0;i<N;i++){
    sum -=(A[i]*A[i])%mod;
  }
  if(sum%2 !=0) sum +=mod;
  sum /=2;
  sum %=mod;
  if(sum<0) sum +=mod;
  cout<<sum<<endl;
}