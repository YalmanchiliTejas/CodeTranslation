#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  ll price;
  ll minp = 100000000000000;
  for(int i = 0; i <= max(2*x,2*y); i+=2){
    price = c * i + max(0,x - i / 2) * a +max(0,y - i / 2) * b;
    minp = min(price, minp);
    price = 0;
  }
  cout << minp << endl;
}

