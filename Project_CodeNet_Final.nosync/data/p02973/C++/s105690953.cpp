#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector <int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  multiset <int> ans;
  for (int i = 0; i < n; i++) {
    auto it = ans.lower_bound(arr[i]);
    if (it == begin(ans)) {
      ans.insert(arr[i]);
    } else {
      it--;
      ans.erase(it);
      ans.insert(arr[i]);
    }
  }
  cout << sz(ans) << '\n';
  return (0);
}
