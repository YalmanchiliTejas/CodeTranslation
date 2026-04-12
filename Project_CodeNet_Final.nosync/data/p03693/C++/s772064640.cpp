#include <bits/stdc++.h>
#define rep(i, s, e) for(int i = s; i < e; i++)
#define rrep(i, s, e) for(int i = s; i > (s)-(e); i--)
#define pr(s) std::cout << s << std::endl
#define prb(s) std::cout << s
using namespace std;



int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);


  int a, b, c;
  cin >> a >> b >> c;

  if ((100*a+10*b+c)%4 == 0) pr("YES");
  else pr("NO");


  return 0;
}
