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

#define INT_MAX 2000000000
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
	string s;
	cin >> s;
	int f = 0;
	rep(i, 0, s.length() - 1) {
		if (s[i] == 'A'&&s[i + 1] == 'C') {
			f = 1;
		}
	}
	if (f) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}