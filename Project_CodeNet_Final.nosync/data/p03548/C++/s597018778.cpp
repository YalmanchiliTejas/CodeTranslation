#include <bits/stdc++.h>
#define rep(i,a) for(int i=0;i<int(a);++i)
using namespace std;
typedef long long ll;
int main() {
  int x, y, z;
	cin >> x >> y >> z;
	int ans = (x-z)/(y + z);
	cout << ans << endl;
}