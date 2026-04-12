#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
long long GCD(long long A,long long B){
  if(B==0){
    return A;
  }
  else{
    return GCD(B,A%B);
  }
}
int main() {
  
  int N;
  cin>>N;
  
  long long x=pow(10,9);
  
  long long y=x+7;
  
  vector<long long> A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  
  long long sum=0;
  for(int i=0;i<N;i++){
    sum+=(A[i]%y);
    sum%=y;
  }
  
  long long ans=0;
  
  
  for(int i=0;i<N-1;i++){
    sum=(sum-A[i])%y;
    ans+=((A[i]%y)*(sum%y))%y;
  }
  
  if(ans>=0){
    cout<<ans%y<<endl;
  }
  else{
    cout<<ans%y+y<<endl;
  }
}