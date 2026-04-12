#include<bits/stdc++.h>
using namespace std;

int A = 0;
int B = 0;
int C = 0;
int X = 0;
int Y = 0;

long long solve() {
  long long price[4] = {0};
  price[0] = A*X + B*Y;
  price[1] = C*(X*2) + ((Y-X > 0) ? B*(Y-X) : 0);
  price[2] = C*(Y*2) + ((X-Y > 0) ? A*(X-Y) : 0);
  price[3] = C*(max(X, Y)*2);
  return min(min(price[0], price[1]), min(price[2], price[3]));
}

int main() {
  cin >> A >> B >> C >> X >> Y;
  printf("%lld\n", solve());
  return 0;
}
