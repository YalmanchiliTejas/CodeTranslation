#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
long long int __lcm(long long int a,long long int b){
  long long int n;
  n=a*b/__gcd(a,b);
  return n;
}
 //__gcd 最大公約数
 //__lcm 最小公倍数
 //double 少数（変数）
//sqrt 平方根
//ceil 天井関数
//floor 床関数
//abs 絶対値
//pow 累乗
//cbrt  立方根
//hypot 平方和の平方根
 
int main() {
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  cout<<min({2*c*max(x,y),a*x+b*y,2*c*min(x,y)+a*max(0,x-y)+b*max(0,y-x)});
  }