#include <bits/stdc++.h>
using namespace std;

int64_t Q=1000000007;

int64_t si(int64_t x,int64_t y){
   int64_t A=x,B=y,C=1;//A,Bを入れる
  for(int64_t i=1;i<=B;i++){
    C=(C*i)%Q;
  }
  int64_t N=Q-2,a=1,b=0,c=1;
  while(N>0){
    a*=2;
    if(N%a!=0){
      N-=a/2;
      int64_t d=C;
      for(int j=0;j<b;j++){
        d=(d*d)%Q;
      }
      c=(c*d)%Q;
    }
    b++;
  }
  C=c;
  for(int i=0;i<B;i++){
    C=(C*(A-i))%Q;
  }//答はC
  return C;
}


int main() {
  int64_t N,M,K;
  cin>>N>>M>>K;
  int64_t Z=((((M*(M+1)*(M-1))/6)%Q)*(N*N)%Q)%Q;
  swap(N,M);
  Z+=((((M*(M+1)*(M-1))/6)%Q)*(N*N)%Q)%Q;
  Z=(Z*si(N*M-2,K-2))%Q;
  cout<<Z<<endl;
}