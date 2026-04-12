#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  int K,Z=1,A,P;
  cin>>S>>K;
  P=K;
  int L=S.size();
  A=S[0]-'0';
  A--;
  for(int i=1;i<=K;i++){
    Z*=(L-i);
    Z/=i;
    Z*=9;
    if(i!=K){
      A*=(L-i);
      A/=i;
      A*=9;
    }
  }
  Z+=A;
  K-=1;
  int X=1;
  while(K>=0&&X<L){
    int B=S[X]-'0';
    if(B){
      A=B;
      A--;
      for(int i=1;i<K;i++){
        A*=(L-i-X);
        A/=i;
        A*=9;
      }
      A*=min(1,K);
      Z+=A;
      A=1;
      for(int i=1;i<=K;i++){
        A*=(L-i-X);
        A/=i;
        A*=9;
      }
      Z+=A;
      K--;
    }
    X++;
    if(X==L&&K==0){
      Z++;
    }
  }
  if(L==1&&P==1){
    Z=S[0]-'0';
  }
  cout<<Z<<endl;
}