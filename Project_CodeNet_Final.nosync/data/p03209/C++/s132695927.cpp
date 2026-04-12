#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <sstream>
#include <fstream>

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

using namespace std;
typedef long long ll;
int N;
ll X;

vector<ll> a(1, 1);
vector<ll> p(1, 1);

ll f(int N, ll X) {
  if (N == 0) {
    if (X <= 0) {
      return 0;
    }
    else {
      return 1;
    }
  }
  else if (X <= 1 + a[N-1]) {
    return f(N-1, X-1);
  }
  else {
    return p[N-1] + 1 + f(N-1, X-2-a[N-1]);
  }
}

int main() {
  cin >> N >> X;  
  for (int i = 0; i < N; ++i) {
    a.push_back(a[i] * 2 + 3);
    p.push_back(p[i] * 2 + 1);
  }

  cout << f(N, X) << endl;
  return 0;
}
