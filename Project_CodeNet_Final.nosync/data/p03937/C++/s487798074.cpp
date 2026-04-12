#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

int h, w;

int main() {
	cin >> h >> w;
	int cnt = 0;
	for (int i = 0; i < h; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < w; ++j)
			if (s[j] == '#')
				++cnt;
	}
	if (cnt == h + w - 1) {
		cout << "Possible\n";
	}
	else {
		cout << "Impossible\n";
	}
	return 0;
}


