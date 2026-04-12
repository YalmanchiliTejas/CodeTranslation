#include <bits/stdc++.h>
using namespace std;

long long N,X,eaten=0;

int rec(){
  if(X==pow(2,N+2)-3){
    eaten+=(pow(2,N+1)-1);
    return 0;
  }else if(X>pow(2,N+1)-1){
    eaten+=(pow(2,N));
    X-=(pow(2,N+1)-1);
    N--;
    rec();
  }else if(X==pow(2,N+1)-1){
    eaten+=(pow(2,N));
    return 0;
  }else if(X>1){
    X--; N--;
    rec();
  }else{
    return 0;
  }
}

int main(){
  cin >> N >> X;
  rec();
  cout << eaten << endl;
}