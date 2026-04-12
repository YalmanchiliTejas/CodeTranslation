#include<bits/stdc++.h>
using namespace std;
int main(){
  int A=0,B=0,C=0,X=0,Y=0,i=0,j=0;
  cin>>A>>B>>C>>X>>Y;
  int low_cost=A*X+B*Y;
  for (int k=0;k<=X || k<=Y;k++){
    i = X-k;
    j = Y-k;
    if (i<=0){
      i=0;
    }
    if (j<=0){
      j=0;
    }
    if (low_cost>i*A+j*B+k*C*2){
      low_cost=i*A+j*B+k*C*2;
    }
  }
  cout<<low_cost;
}