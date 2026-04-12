#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C, X, Y;
  long long minprice = 1000000000000;
  cin >> A >> B >> C >> X >> Y;
  for(int i = 0; i < 200000; i++){
    int price = 0;
    price = 2 * C * i + max(0, (X-i) * A) + max(0, (Y-i)*B);
    if(minprice > price) minprice = price;
  }
  cout << minprice << '\n';
  return 0;
}