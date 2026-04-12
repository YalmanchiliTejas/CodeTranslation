#include <bits/stdc++.h>
using namespace std;

long long N,X;
long long T[50];
long long P[50];

long long countpati(long long N,long long X){
  if(X==1){
    if(N==0){
      return 1;
    }
    else return 0;
  }
  if(1<X && X<=1+T[N-1]){
    return countpati(N-1,X-1);
  }
  if(X==2+T[N-1]){
    return 1+P[N-1];
  }
  if(2+T[N-1]<X && X<=2+2*T[N-1]){
    return P[N-1]+1+countpati(N-1,X-2-T[N-1]);
  }
  if(X==3+2*T[N-1]){
    return 2*P[N-1]+1;
  }
}



int main(){

  cin>>N>>X;
  
  T[0]=1;
  P[0]=1;
  for(int i=0;i<=48;i++){
    T[i+1]=T[i]*2+3;
    P[i+1]=P[i]*2+1;
  }
  
  long long ans=countpati(N,X);
  cout<<ans<<endl;
  
  return 0;
}
