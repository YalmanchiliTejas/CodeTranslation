#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;

  if(x<y) {
    swap(x,y);
    swap(a,b);
  }

  int ans = 0;
  if(a+b>c*2){
    ans+=y*c*2;
    x-=y;
    if(a>c*2){
      ans+=x*c*2;
    }
    else
    {
      ans+=x*a;
    }
  }
  else{
    ans+=x*a+y*b;
  }
   cout << ans << endl; 
  
}