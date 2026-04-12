#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <bitset>
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define index(xs, x) (int)(lower_bound(all(xs), x) - xs.begin())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007

int N, K;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N >> K;
  long long s = 0;
  for (int b=K+1; b<=N; b++) {
    for (int a=0; a<=N; a+=b) {
      int hi = b-1;
      if (a+b > N) {
        hi = N%b;
        if (hi < K) continue;
      }
      s += (hi-K+1);
      if (a == 0 && K == 0) s--;
    }
  }
  cout << s << "\n";
  return 0;
}
