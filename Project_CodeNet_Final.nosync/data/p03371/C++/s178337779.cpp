#include <bits/stdc++.h>
using namespace std;

void chmin(int& a, int b){
  if (a > b) a = b;
}
int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  
  int ans = 1000000000;
  // ABピザを固定
  if (X >= Y) {
    // ABピザでAピザBピザ i枚分買った
    for (int i = 0; i <= X; i++) {
      int price = C * 2 * i + A * (X-i) + B * max(Y-i, 0);
      
      chmin(ans, price);

    }
  } else {
    for (int i = 0; i <= Y; i++) {
      int price = C * 2 * i + A * max(X-i, 0) + B * (Y-i);
      
      chmin(ans, price);
    }
  }
  cout << ans << endl;

}