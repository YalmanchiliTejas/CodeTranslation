#include <iostream>
#include <algorithm>
#include <array>
#include <cstdlib>
#include <functional>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string>
#include <vector>

#define INF 1000000000
#define MOD 1000000007
#define ll long long
#define rep(i,a,b) for(i = (a); i < (b); i++)
#define bitget(a,b) (((a) >> (b)) & 1)
#define vint vector<int>
#define vvint vector<vector<int>>
#define vsort(x) sort(x.begin(),x.end())

using int64 = uint64_t;

using namespace std;

int main() {

	int i, j, k;
	vint a(12);
	rep(i, 0, 12)
		cin >> a[i];
	vsort(a);
	int flag = 1;
	rep(i, 0, 3) {
		if (a[i] != a[i + 1]) {
			flag = 0;
		}
	}
	rep(i, 4, 7) {
		if (a[i] != a[i + 1]) {
			flag = 0;
		}
	}
	rep(i, 8, 11) {
		if (a[i] != a[i + 1]) {
			flag = 0;
		}
	}
	if (flag) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	return 0;
}