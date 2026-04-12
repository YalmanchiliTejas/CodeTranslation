#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,ab,x,y;
  cin >> a >> b >> ab >> x >> y;
  int ans=0;
  if(a+b>ab*2){
    ans+=min(x,y)*ab*2;
    if(x>y){
      ans+=min(ab*(x-y)*2,a*(x-y));
    }else{
      ans+=min(ab*(y-x)*2,b*(y-x));
    }
  }else{
    ans=a*x+b*y;
  }
  cout << ans << endl;
  return 0;
}