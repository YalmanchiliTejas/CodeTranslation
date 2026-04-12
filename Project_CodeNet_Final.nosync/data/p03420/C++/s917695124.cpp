#include<iostream>
#include<string>
using namespace std;
int main(){
  long long N,K;
  cin>> N >>K;
  int i;
  long long ans=0;
  if(K==0){
    ans=N*N;
  }else{
  for(i=K+1;i<=N;i++){
    ans+=(N/i)*(i-K);
    if(N%i>=K){
      ans+=N%i-K+1;
    }
  }
  }
  cout<<ans;
  return 0;
}
