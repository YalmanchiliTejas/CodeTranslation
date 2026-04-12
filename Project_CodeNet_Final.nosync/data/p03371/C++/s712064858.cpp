#include <bits/stdc++.h>
using namespace std;
long long a,b,c,x,y,ans=0;
string s;
int main(){
  cin >> a >> b >> c >> x >> y;
  if(a+b>=2*c){
    ans+=min(x,y)*2*c;
    if(x>y){
      ans+=min((x-y)*a,(x-y)*2*c);
    }else{
      ans+=min((y-x)*b,(y-x)*2*c);
    }
  }else{
    ans+=a*x+b*y;
  }
  cout << ans << endl;
  return 0;
}