#include <bits/stdc++.h>

#define REPI(x) for(int i=0;i<x;i++)
#define REPJ(x) for(int j=0;j<x;j++)

#define REPISE (s,e) for(int i=s,i<e;i++)
#define REPJSE (s,e) for(int j=s,j<e;j++)

typedef long long ll;

using namespace std;

int main ()
{
  int A,B,C,X,Y,res,price;
  vector<int> prices;

  cin >> A >> B >> C >> X >> Y;
  
  price = A*X + B*Y;
  prices.push_back (price);

  price = C*X*2 + B*max(Y-X,0);
  prices.push_back (price);

  price = C*Y*2 + A*max(X-Y,0);
  prices.push_back (price);

  res = prices[0];
  REPI(prices.size())
    res = min (res,prices[i]);

  cout << res << endl;
  return 0;
}