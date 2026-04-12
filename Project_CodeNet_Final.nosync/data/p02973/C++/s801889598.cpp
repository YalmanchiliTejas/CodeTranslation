#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
int main() {
  int n;
  cin >> n;
  multiset<int> l;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    auto it = l.lower_bound(x);
    if (it == l.begin())
      l.insert(x);
    else {
      it--;
      l.erase(it);
      l.insert(x);
    }
  }
  cout << l.size() << endl;
}