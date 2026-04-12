#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull maxi(ull a, ull b){
  if (a>b) return a;
  else return b;
}

int main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  
  ull ans=0;
  if(A+B<2*C){
    ans+=(A+B)*min(X,Y);
  }else{
    ans+=2*C*min(X,Y);
  }
  
  int R=max(X,Y)-min(X,Y);
  if(max(X,Y)==X){
    if(A*R<2*C*R){
      ans+=A*R;
    }else{
      ans+=2*C*R;
    }
  }
  else if(max(X,Y)==Y){
    if(B*R<2*C*R){
      ans+=B*R;
    }else{
      ans+=2*C*R;
    }
  }
  cout << ans <<endl; 
}