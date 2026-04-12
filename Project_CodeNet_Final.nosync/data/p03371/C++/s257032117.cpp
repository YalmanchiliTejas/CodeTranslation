#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
  int a,b,c,x,y,t,res=0;
  cin >> a >> b >> c >> x >> y;
  if(x<y){
    t=x; x=y; y=t;
    t=a; a=b; b=t;
  }
  if(a+b<=2*c)
    res=a*x+b*y;
  else
    res=2*c*y+min(a,2*c)*(x-y);
  cout << res << endl;
  return 0;
}