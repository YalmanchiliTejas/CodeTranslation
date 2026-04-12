#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main(){
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int ans = INF;
  for(int i = 0; i <= 2*max(X, Y); i += 2){
    int a = max(0, X - i/2);
    int b = max(0, Y - i/2);
    ans = min(ans, a*A + b*B + C*i);
  }
  cout << ans << endl;
  return 0;
}
