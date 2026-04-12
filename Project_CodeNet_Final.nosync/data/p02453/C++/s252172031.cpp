#include <bits/stdc++.h>

using namespace std;

int lower_bound(vector<int>& v, int istart, int iend, int value) {
  int n = v.size();
  int ng = -1;
  int ok = v.size();

  while (abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;

    if (v[mid] >= value) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  return ok;
}

int main() {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  int num_query;
  cin >> num_query;

  int query;
  for (int i = 0; i < num_query; i++) {
    cin >> query;
    cout << lower_bound(v, 0, v.size(), query) << endl;
  }
}


