#include <iostream>

using namespace std;
typedef long long  ll;
#define rep(i,s,n)for(ll i = s;i<n;i++)

int main() {
	int r, g, b; cin >> r >> g >> b;
	cout << (((100 * r + 10 * g + b) % 4 == 0) ? "YES" : "NO") << endl;

	return 0;
}