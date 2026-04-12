#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)

using ll = long long;

int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int m = min(x,y);
  int ans1 = 0, ans2 = 0, ans3 = 0;
  //余らせるab。ちょうどにするab。別々の購入
  ans1 = 2*c*max(x,y);
  ans2 = 2*m*c + a*(x-m) + b*(y-m);
  ans3 = a*x+b*y;
  int ans = min(ans1,min(ans2,ans3));
  //こんなきっかりとは限らないということ?
  cout<<ans<<endl;
  return 0;
}