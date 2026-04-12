#include <bits/stdc++.h>
using namespace std;
#define SORT(a) sort((a).begin(), (a).end())
#define RSORT(a) reverse((a).begin(), (a).end())
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(a) ((a).begin(), (a).end())
typedef long long ll;
const long long INF = 1LL << 60;
// const int INF=1010101010;
// using Graph = vector<vector<int>>;

vector<long long> P(55);  //パティの枚数
vector<long long> N(55);  //レベル

ll rec(int i, ll x) {
  if (i == 0)
    return x;
  else if (x == 0 || x == 1)
    return 0;
  else if (x == N[i])
    return P[i];
  else if (x <= N[i - 1] + 1)
    return rec(i - 1, x - 1);
  else if (x <= N[i] - 1)
    return 1 + P[i - 1] + rec(i - 1, x - 2 - N[i - 1]);
  else
    return 0;
}

int main() {
  int n;
  long long x;
  cin >> n >> x;
  N[0] = 1;
  P[0] = 1;
  for (int i = 0; i < n; i++) {
    N[i + 1] = 3 + 2 * N[i];
    P[i + 1] = 1 + 2 * P[i];
  }
  cout << rec(n, x) << endl;
}