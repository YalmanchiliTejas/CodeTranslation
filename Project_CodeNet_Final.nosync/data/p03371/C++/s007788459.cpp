#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  C*=2;
  int64_t j=10000000000;
  for(int i=0;i<=max(X,Y);i++){
    j=min(j,(int64_t)(A*max(0,X-i)+B*max(0,Y-i)+C*i));
  }
  cout<<j<<endl;
}