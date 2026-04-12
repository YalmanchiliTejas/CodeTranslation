#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int r,g,b;
  cin>>r>>g>>b;
  int x = r*100+10*g+b;
  if (x%4==0) puts("YES");
  else puts("NO");
  return 0;
}
