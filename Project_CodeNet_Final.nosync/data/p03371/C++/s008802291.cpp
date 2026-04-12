#include<bits/stdc++.h>
using namespace std;
int main()
{
  int A,B,C,X,Y;
  int ans=0;
  cin>>A>>B>>C>>X>>Y;
  int big=max(X,Y);
  int sma=min(X,Y);
  if(A+B>2*C && X>Y)
  {
    if(2*C*sma+A*(X-Y)<=2*C*big)
    {
    ans=2*C*sma+A*(X-Y);
  }else{
    ans=2*C*big;
  }
  }
  if(A+B>2*C && X<=Y)
  {
    if(ans=2*C*sma+B*(Y-X)<=2*C*big)
    {
    ans=2*C*sma+B*(Y-X);
  }else{
    ans=2*C*big;
  }
  }
  if(A+B<=2*C)
  {
    ans=A*X+B*Y;
  }
  cout<<ans<<endl;
  return 0;

}
