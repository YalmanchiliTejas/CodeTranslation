#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;
using ll = long long;

int a,b,c,x,y;
ll num[4];

int main(){
  cin >> a >> b >> c >> x >> y;
  ll ans = a * x + b * y;
  num[0] = x;
  num[1] = y;
  num[2] = 0;
  if(a + b > 2*c){
    int s = min(num[0], num[1]);
    num[0] -= s;
    num[1] -= s;
    num[2] += s * 2;
    //cout << num[0] << endl;
    ans = num[0] * a + num[1] * b + num[2] * c;
  }
  if(a > 2 * c){
    int k = num[0];
    num[0] = 0;
    num[2] += 2 * k;
    ans = num[0] * a + num[1] * b + num[2] * c;
  }
  if(b > 2 * c){
    int k = num[1];
    num[1] = 0;
    num[2] += 2 * k;
    ans = num[0] * a + num[1] * b + num[2] * c;
  }
  cout << ans << endl;


}