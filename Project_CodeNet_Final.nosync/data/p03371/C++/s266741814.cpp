#include <iostream>
#include <string>
#include <vector>
#define REP(i,k,n) for(int(i)=(k);(i)<(n);++(i))
using namespace std;

int A,B,C,X,Y;
const int N = 1e5 + 10;
const int INF = 1e9;

int main()
{
  cin >> A >> B >> C >> X >> Y;

  int price_min = INF;
  REP(i,0,N) {
    int price = i * 2 * C + max(0, X-i) * A + max(0, Y-i) * B;
    // price_min = min(price_min, price);
    if (price < price_min) price_min = price;
  }

  cout << price_min << endl;
  return 0;
}