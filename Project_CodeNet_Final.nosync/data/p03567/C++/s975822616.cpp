#include <cstdio>
#include <iostream> 
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;
using ll = long long;

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	int f = 0, i, n;
	string s;

	cin >> s;
	n = s.length();

	for (i = 0; i < n - 1; i++) {
		if (s[i] == 'A' && s[i + 1] == 'C') {
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