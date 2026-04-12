#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector <long long> v(n);

  for (long long &x: v)
    cin >> x;

  sort(v.rbegin(), v.rend());
  
  long long ans = 0;
  bool changed = true;
  while (changed) {
    changed = false;
    for (int i = 0; i < n; ++i) {
      long long dif = v[i] - (v[i] % n);
      if (dif > 0) {
	changed = true;
	long long val = dif / (n);
	ans += val;
	v[i] %= n;
	for (int j = 0; j < n; ++j) {
	  if (j != i)
	    v[j] += val;
	}
      }
    }
  }

  cout << ans << endl;
}
