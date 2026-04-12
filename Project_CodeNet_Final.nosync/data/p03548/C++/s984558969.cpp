#include <bits/stdc++.h>

#define REP(i,n) for(int i=0; i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
using namespace std;

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	int res = 0;
	for (int i = y + 2 * z; i <= x; i += y + z) {
		res++;
	}
	cout << res << endl;
	return 0;
}