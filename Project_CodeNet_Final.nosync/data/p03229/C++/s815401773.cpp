#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  sort(A.begin(), A.end(), greater<ll>());
  deque<ll> que{};
  ll ans = 0;
  que.push_back(A[0]);
  int idr = N - 1, idl = 1;
  if (N % 2 == 1) {
    ans += max(abs(A[N / 2 - 1] - A[N / 2]), abs(A[N / 2 + 1] - A[N / 2]));
    N--;
  }
  for (int i = 1; i < N; i++) {
    if (i % 4 == 1) {
      que.push_front(A[idr]);
      idr--;
    } else if (i % 4 == 2) {
      que.push_back(A[idr]);
      idr--;
    } else if (i % 4 == 3) {
      que.push_front(A[idl]);
      idl++;
    } else if (i % 4 == 0) {
      que.push_back(A[idl]);
      idl++;
    }
  }

  ll past = que.front();
  que.pop_front();
  while (!que.empty()) {
    ans += abs(past - que.front());
    past = que.front();
    que.pop_front();
  }
  cout << ans << endl;
}