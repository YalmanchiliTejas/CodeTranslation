#include <iostream>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define in(v) cin>>v;
#define out(v) cout<<v<<"\n"

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int N; in(N);

  int max_h = 0, ans = 0;
  rep(i, N) {
    int a; in(a);
    if (max_h <= a)
      ++ans;
    max_h = max(max_h, a);
  }
  out(ans);

  return 0;
}
