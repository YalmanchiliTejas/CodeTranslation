#include <bits/stdc++.h>
using namespace std;

int main(void){
  int A, B, C, X, Y;
  cin >> A>> B>> C>> X>> Y;

  int ans = INT_MAX;
  ans = min(ans, A*X + B*Y);
  int res = ans;

  for(int i = 0; i < max(X, Y)*2+2; i++){
    int sum = ans;
    int c = i+1;
    int c1 = c, c2 = c;
    if(c > X) c1 = X;
    if(c > Y) c2 = Y;
    sum -= (A*c1 + B*c2);
    sum += 2*c*C;
    res = min(res, sum);
  }
  cout << res << endl;
}
