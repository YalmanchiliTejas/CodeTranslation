#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  ll A[N];
  for (int i = 0; i < N; i++) cin >> A[i];
  multiset<ll> Set;
  Set.insert(A[0]);
  for (int i = 1; i < N; i++) {
    auto itr = Set.lower_bound(A[i]);
    if (itr == Set.begin()) {
      Set.insert(A[i]);
    } else {
      auto itr2 = prev(itr,1);
      Set.erase(itr2);
      Set.insert(A[i]);
    }
  }
  int ans = Set.size();
  cout << ans << endl;
  return 0;
}