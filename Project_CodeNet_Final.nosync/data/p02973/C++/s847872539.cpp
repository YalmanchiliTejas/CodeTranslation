#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }

const int maxn = 1e5 + 11;

int N;
multiset<int> grps;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;

  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    if (grps.empty() || *grps.begin() >= x) {
      grps.insert(x);
    } else {
      auto ptr = grps.lower_bound(x);
      --ptr;
      grps.erase(ptr);
      grps.insert(x);
    }
  }

  cout << grps.size() << "\n";

  return 0;
}
