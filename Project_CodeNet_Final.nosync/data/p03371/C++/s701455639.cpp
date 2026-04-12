#include <bits/stdc++.h>
using namespace std;

int main() {
  long a, b, c, x, y;
  cin>>a>>b>>c>>x>>y;
  long ans = 1e10;
  for (int i=0; i<=max(2*x, 2*y); i+=2) {
    int na = max(x - i / 2, 0l);
    int nb = max(y - i / 2, 0l);
    ans = min(a * na + b * nb + c * i, ans);
  }
  cout<<ans<<endl;
}