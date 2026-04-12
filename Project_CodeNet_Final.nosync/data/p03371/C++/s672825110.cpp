#include<bits/stdc++.h>

using namespace std;

int main(){
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  long long ans = 1e9;
  
  int lim = max(X, Y) * 2 + 1;
  for (int i=0; i<=lim; i++){
    int a = max(X - i / 2, 0);
    int b = max(Y - i / 2, 0);
    ans = min(ans, (long long)(A *a + B * b + C * i));
  }
  cout << ans << endl;
  return 0;
}