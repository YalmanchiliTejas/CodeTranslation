#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	
	int x, y, z;
	cin >> x >> y >> z;
	x -= z;
	y += z;
	cout << x/y << endl;
	
	return 0;
}
