#include <iostream>
#include<vector>
#include<algorithm>
#include <queue>
#include <string>
#include <set>
#include <bitset>

using namespace std;
#define ff(i,n,m) for(int i=n;i<m;i++)
#define i64 int64_t
#define tos(x) to_string(x)


int main() {
	int n;
	cin >> n;
	int ans = 0;
	ff(i, 0, n) {
		ans += 800;
		if (i % 15 == 14) {
			ans -= 200;
		}
	}
	cout << ans << endl;
	return 0;
}