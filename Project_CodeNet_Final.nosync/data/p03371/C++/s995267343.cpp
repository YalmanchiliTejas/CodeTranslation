#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;


  int p_min = INT_MAX;
  int max_xy = max(X, Y);

  for(int r=0; r<=2*max_xy; r+=2){
    int p = max(X - r / 2, 0);
    int q = max(Y - r / 2, 0);
    int price = A * p + B * q + C * r;
    p_min = min(price, p_min);
    // cout << p << ',' << q << ',' << r << ',' << price << "," << p_min << endl;
  }
  cout << p_min << endl;
}
