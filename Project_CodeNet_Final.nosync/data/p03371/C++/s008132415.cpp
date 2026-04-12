#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
using ll = long long;
using P = pair<ll,ll>;

int main(){
  ll a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  c = c*2;
  if (a + b <= c){
    cout << a*x +b*y << endl;
  }
  else if (a + b > c){
    if (x > y){
      ll sum1 = a * (x-y) + c * y;
      ll sum2 = c * x;
      cout << min(sum1,sum2) << endl;
    }
    else {
      ll sum1 = b * (y-x) + c * x;
      ll sum2 = c * y;
      cout << min(sum1,sum2) << endl;
    }
  }
}