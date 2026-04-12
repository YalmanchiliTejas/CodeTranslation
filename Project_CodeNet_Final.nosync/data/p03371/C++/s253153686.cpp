#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
typedef long long ll;


int main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  int res = A * X + B * Y;
  res = min(res,(C*2)*max(X,Y));
  res = min(res,min(X,Y) * 2 * C + A *(X - min(X,Y)) + B * (Y - min(X,Y)));
  cout << res << endl;
  return 0;
}