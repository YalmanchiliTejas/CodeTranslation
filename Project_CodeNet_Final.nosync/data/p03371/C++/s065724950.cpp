#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main(){
  int A,B,C,X,Y,s;cin>>A>>B>>C>>X>>Y;s=A*X+B*Y;
  for(int i=0;i<=max(X,Y);i++){
    s=min(s,max(X-i,0)*A+max(Y-i,0)*B+i*2*C);
  }
  cout<<s<<endl;
}