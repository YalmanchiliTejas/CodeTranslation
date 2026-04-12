#include <iostream>
#include<vector>
#include<algorithm>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include<iomanip>

using namespace std;
#define ff(ii,nn,mm) for(int ii=nn;ii<mm;ii++)
#define i64 int64_t
#define tos(x) to_string(x)

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	int ans = 0;
	int len = y+2*z;
	while (len <= x) {
		len += y + z;
		ans++;
	}
	cout << ans << endl;
	return 0;
}