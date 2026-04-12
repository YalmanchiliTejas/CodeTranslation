#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;

  int ans1 = a*x+b*y;
  int ans2,ans3;
  if(x>y){
    ans2 = c*2*y + a*(x-y);
    ans3 = c*2*x;
  }
  else{
    ans2 = c*2*x + b*(y-x);
    ans3 = c*2*y;
  }
  cout << min({ans1,ans2,ans3}) << endl;
}