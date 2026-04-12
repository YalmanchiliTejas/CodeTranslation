#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
  int A,B,C,X,Y,ans1,ans2,ans3,ans4;
  cin>>A>>B>>C>>X>>Y;
  ans1=A*X+B*Y;
  ans2=C*Y*2+A*(X-Y);
  if(X-Y<0) ans2=ans1;
  ans3=C*X*2+B*(Y-X);
  if(Y-X<0) ans3=ans1;
  ans4=max(X,Y)*C*2;
  
  cout<<min(min(ans1,ans4),min(ans2,ans3))<<endl;
}
