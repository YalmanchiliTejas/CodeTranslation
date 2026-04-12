#include <bits/stdc++.h>
using namespace std;
using lint = long long;

const int MAXN = 200005;

int N;
long long A[MAXN];
long long Answer[MAXN];

void Read() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
}

bool used[MAXN];
long long pref[MAXN][2]; // (even, odd) only

void Solve() {
  priority_queue<pair<long long, pair<int, int>>> pq;
  set<int> unused;

  for (int i = 1; i <= N; i++) {
    pq.push({A[i], {i, i + 1}});
  }

  for (int i = 0; i <= N + 2; i++) {
    unused.emplace(i);
  }

  for (int i = 1; i <= N + 2; i++) {
    pref[i][0] = pref[i - 1][0];
    pref[i][1] = pref[i - 1][1];
    pref[i][i & 1] += A[i];
  }

  int num = 0;
  long long ans = 0;

  while (!pq.empty()) {
    long long w = pq.top().first;
    int u = pq.top().second.first;
    int v = pq.top().second.second;
    pq.pop();
    if (used[u] || used[v]) continue;

    used[u] = true, used[v] = true;
    unused.erase(u);
    unused.erase(v);

    Answer[++num] = (ans += w);

    int L = *prev(unused.lower_bound(u));
    int R = *unused.lower_bound(v);

    if (1 <= L && R <= N + 1) {
      long long NotTakeUV = (pref[R - 1][L & 1] - pref[L - 1][L & 1]);
      long long TakeUV = (pref[R - 1][(L & 1) ^ 1] - pref[L - 1][(L & 1) ^ 1]);
      pq.push({NotTakeUV - TakeUV, {L, R}});
    }
  }
}

void Write() {
 cout << Answer[N/2];
}

int main() {
  Read();
  Solve();
  Write();
  return 0;
}
