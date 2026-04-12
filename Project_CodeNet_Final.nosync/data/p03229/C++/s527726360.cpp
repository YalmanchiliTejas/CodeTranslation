#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;
using vi = vector<int>;

#define all(a) (a).begin(),(a).end()
#define rep(i,n) for(int i=0;i<(n);++i)
#define in(v) cin>>v;
#define out(v) cout<<v<<"\n"
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int N; in(N);

  vi A(N);
  rep(i, N) {
    in(A[i]);
  }
  sort(all(A));

  vi p(N);
  rep(i, N-1) {
    if (i % 2 == 0) {
      ++p[i]; --p[i+1];
    } else {
      --p[i]; ++p[i+1];
    }
  }
  sort(all(p));
  ll sum = 0, sum2 = 0;
  rep(i, N) {
    sum += p[i] * A[i];
    sum2 -= p[i] * A[N-1-i];
  }
  out(max(sum, sum2));

  return 0;
}
