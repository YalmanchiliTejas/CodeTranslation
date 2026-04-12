#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
  ll A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  ll ans1 = A*X + B*Y;
  ll ans2 = 2*C*max(X, Y);
  ll ans3;
  if(X <= Y) ans3 = C*2*X + (Y-X)*B;
  else if(X > Y)  ans3 = C*2*Y + (X-Y)*A;
  cout << min(ans1, min(ans2, ans3)) << endl;
  return 0;
}