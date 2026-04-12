#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int A,B,C;cin>>A>>B>>C;
  int X=C+10*B+100*A;
  
  if(X%4==0){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}