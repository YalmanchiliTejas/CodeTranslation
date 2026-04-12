#include<algorithm>
#include<cmath>
#include<cstdint>
#include<cstdio>
#include<functional>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>
using namespace std;

#define loop(i,a,b) for(int i=(a); i<(b); ++i)
#define rep(i,n) for(int i=0; i<n; ++i)
#define all(v) begin(v), end(v)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

const double PI = acos(-1.0);

int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  auto w = v;
  sort(all(w));
  auto a = w[n/2];
  auto b = w[n/2-1];

  rep(i, n) {
          if (w[n/2] <= v[i]) {
                  cout << b << endl;
          } else {
                  cout << a << endl;
          }
  }
  return 0;
}
