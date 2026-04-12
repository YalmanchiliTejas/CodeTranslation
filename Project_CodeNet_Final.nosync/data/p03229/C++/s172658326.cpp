#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n; cin >> n;
  vector<int> a;
  for (int i = 0; i < n; i++) {
	int t; cin >> t;
	a.push_back(t);
  }
  sort(a.begin(), a.end());
  long long res1 = 0, res2 = 0;
  if (n % 2 == 1) {
	for (int i = 0; i < n; i++) {
	  if (i <= (n - 2) / 2) {
		res1 += -2 * a[i];
	  }
	  else if (i == (n - 2) / 2 + 1) {
		res1 += a[i];
	  }
	  else if (i == (n - 2) / 2 + 2) {
		res1 += a[i];
	  }
	  else {
		res1 += 2 * a[i];
	  }
	}
	for (int i = 0; i < n; i++) {
	  if (i < (n - 2) / 2) {
		res2 += -2 * a[i];
	  }
	  else if (i == (n - 2) / 2 || i == (n - 2) / 2 + 1) {
		res2 += -1 * a[i];
	  }
	  else {
		res2 += 2 * a[i];
	  }
	}
	cout << max(res1, res2) << endl;
	return 0;
  }
  else {
	for (int i = 0; i < n; i++) {
	  if (i < (n - 2) / 2) {
		res1 += -2 * a[i];
		res2 += 2 * a[i];
	  }
	  else if (i == (n - 2) / 2 ) {
		res1 += -1 * a[i];
		res2 += -1 * a[i];
	  }
	  else if (i == (n - 2) / 2 + 1) {
		res1 += a[i];
		res2 += a[i];
	  }
	  else {
		res1 += 2 * a[i];
		res2 += -2 * a[i];
	  }
	}
	cout << max(res1, res2) << endl;
	return 0;
  }
  return 0;
}

