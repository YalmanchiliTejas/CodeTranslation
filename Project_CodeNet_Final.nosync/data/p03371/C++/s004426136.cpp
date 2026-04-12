#include<iostream>
using namespace std;
int main(){

  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  int set=C*2;
  int ans=0;
  int min=0;
  if(A+B>set){
  
    if(X<Y)min=X;
    else min=Y;
    ans+=set*min;
    X-=min;
    Y-=min;
  }
  else {
  
    cout<<X*A+Y*B;
    return 0;
  }
  if(A<set)ans+=A*X;
  else ans+=set*X;
  if(B<set)ans+=B*Y;
  else ans+=set*Y;
  cout<<ans;
  return 0;
}