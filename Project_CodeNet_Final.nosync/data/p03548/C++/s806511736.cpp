#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;

int asc(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int main() {
	int x, y, z;
	int ans = 0;
	cin >> x >> y >> z;
	ans = x / (y + z);
	if(x % (y+z) < z) ans--;
	cout << ans << endl;
}