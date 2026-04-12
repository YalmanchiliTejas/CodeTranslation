#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int) n; i++)
using ll = long long;
template <class T>
using vt = std::vector<T>;
using vvi = std::vector<vt<int>>;

int main(){
  int a,b,c,x,y;
  std::cin >> a >> b >> c >> x >> y;

  int piza_a = 0;
  int piza_b = 0;
  int piza_ab = x+y;
  int ans = piza_ab*2*c;
  while (piza_ab >= 0) {
    if(x >= piza_ab)
      piza_a = x - piza_ab;
    if(y >= piza_ab)
      piza_b = y - piza_ab;

    int min = a*piza_a + b*piza_b + c*piza_ab*2;
    if(min < ans)
      ans = min;
    piza_ab--;
  }

  std::cout << ans << '\n';
  return 0;
}
