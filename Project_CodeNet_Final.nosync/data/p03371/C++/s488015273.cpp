#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int money = 1e9;
  for(int i = 0; i < X + Y; i++) {
    money = min(money, (i*2*C)+max(0, X-i)*A+max(0, Y-i)*B);
  }
  cout << money << endl;

  return 0;
}
