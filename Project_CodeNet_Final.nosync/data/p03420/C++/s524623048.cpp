#include<bits/stdc++.h>
using namespace std;
int main(){
  #define int long
  int N,K,r=0;
  const int lz=0;
  cin>>N>>K;
  if(N==1){
    cout<<1;
    return 0;
  }
  if(!K){
    cout<<N*N;
    return 0;
  }
  for(int b=1;b<=N;++b)r+=max((b-K)*(N/b),lz)+max(N-(N/b)*b+1-K,lz);
  cout<<r;
  return 0;
}