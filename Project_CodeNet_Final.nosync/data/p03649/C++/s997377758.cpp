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
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007

long long N;
long long A[50];

bool f(long long X) {
  long long sum = 0;
  rep(i, N) {
    long long x = A[i] + X;
    if (x <= N-1) continue;
    sum += (x-(N-1)+N)/(N+1);
  }
  //cout<<"f("<<X<<") = "<<(sum<=X)<<"\n";
  return sum <= X;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N;
  rep(i, N) cin >> A[i];
  long long m = (1LL<<60);
  rep(d, N) {
    long long lo = -1, hi = 100000000000000000;
    while (hi - lo > 1) {
      long long mid = (lo + hi) / 2LL;
      if (f(mid*N+d)) hi = mid;
      else lo = mid;
    }
    m = min(m, hi*N+d);
  }
  cout << m << "\n";
  return 0;
}
