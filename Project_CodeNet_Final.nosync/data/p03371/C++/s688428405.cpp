#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  
  long long num=0;
  long long ans=10000000000;
  if(X<Y)
  {
    for(int i=0;i<X*2+1;i+=2)
    {
      num=A*(X-i/2)+B*(Y-i/2)+C*i;
      if(num<ans) ans=num;
    }
    for(int i=X*2;i<Y*2+1;i+=2)
    {
      num=B*(Y-i/2)+C*i;
      if(num<ans) ans=num;
    }
  }
  else
  {
    for(int i=0;i<Y*2+1;i+=2)
    {
      num=A*(X-i/2)+B*(Y-i/2)+C*i;
      if(num<ans) ans=num;
    }
    for(int i=Y*2;i<X*2+1;i+=2)
    {
      num=A*(X-i/2)+C*i;
      if(num<ans) ans=num;
    }
  }
  
  cout << ans << endl;
  return 0;
}