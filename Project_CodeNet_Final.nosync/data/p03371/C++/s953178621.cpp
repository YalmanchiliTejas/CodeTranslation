#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int cost, m = 2 * C * 100000;
  for(int i = 0; i <= 100000; i++){
    cost = 2 * C * i + max(0, X - i) * A + max(0, Y - i) * B;
    m = min(m, cost);
  }
  cout << m << endl;
}
