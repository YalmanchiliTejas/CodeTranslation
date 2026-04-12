#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void Main()
{
  ll A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  ll minPrice;
  // それぞれ購入
  minPrice = A*X + B*Y;
  // 少ない数だけセットで購入
  ll setPrice = C * min(X,Y) * 2;
  if (X < Y) setPrice += (Y-X) * B;
  else setPrice += (X-Y) * A;
  minPrice = min(minPrice, setPrice);
  // 全てセットで購入
  minPrice = min(minPrice, C*max(X,Y)*2);
  
  cout << minPrice << endl;
}

int main()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  Main();
  return 0;
}