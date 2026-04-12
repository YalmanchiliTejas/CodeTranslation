#include <bits/stdc++.h>
using namespace std;

const string YES = "YES";
const string NO = "NO";

void solve(long long X) {
  if (X == 7 || X == 5 || X == 3)
    cout << "YES" << endl;
  else
    cout << NO << endl;
}

int main() {
  long long X;
  scanf("%lld", &X);
  solve(X);
  return 0;
}
