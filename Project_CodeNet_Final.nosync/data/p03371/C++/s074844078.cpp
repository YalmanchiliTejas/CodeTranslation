#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

int main() {
  int a_price, b_price, ab_price, a_need, b_need;
  cin >> a_price >> b_price >> ab_price >> a_need >> b_need;
  int cost = 0;
  if (a_price + b_price > ab_price * 2) {
    // buy ab pizza
    cost = min(a_need, b_need) * ab_price * 2;
  } else {
    // buy a and b separately
    cost = min(a_need, b_need) * (a_price + b_price);
  }
  if(a_need > b_need) {
    if (a_price > ab_price * 2) {
      cost += abs(a_need - b_need) * ab_price * 2;
    } else {
      cost += abs(a_need - b_need) * a_price;
    }
  } else {
    if (b_price > ab_price * 2) {
      cost += abs(a_need - b_need) * ab_price * 2;
    } else {
      cost += abs(a_need - b_need) * b_price;
    }
  }
  cout << cost;
}
