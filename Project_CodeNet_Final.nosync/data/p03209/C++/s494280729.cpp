#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long burgernum(int n){
  long s;
  long ss;
  if (n==0){
    s=1;
    return s;
  }
  else{
    ss=burgernum(n-1);
    s=3+2*ss;
    return s;
  }
}
long burgerpnum(int n){
  long s;
  long ss;
  if (n==0){
    s=1;
    return s;
  }
  else{
    ss=burgerpnum(n-1);
    s=1+2*ss;
    return s;
  }
}
long burgers(int n,long L){
  long s;
  long ss;
  if (n==0){
    s=L;
    return s;
  }
  else{
    ss=burgernum(n-1);
    if (L==0){
      s=0;
    }
    else if (L==2*ss+3){
      s=burgerpnum(n);
    }
    else if (L==ss+2){
      s=burgerpnum(n-1)+1;
    }
    else if (L<ss+2){
      s=burgers(n-1,L-1);
    }
    else{
      s=burgerpnum(n-1)+1+burgers(n-1,L-ss-2);
    }
  }
  return s;
}

int main(){
  int N;
  long L;
  cin>>N;
  cin>>L;
  //cout<<burgerpnum(N-1)<<endl;
  cout<<burgers(N,L);
  return 0;
}
