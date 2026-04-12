#define _ijps 0
#define _ALLOW_RTCc_IN_STL
#define _CRT_SECURE_NO_DEPRECATE
//#pragma comment(linker, "/STACK:667772160")
#include <iostream>
#include <cmath>
#include <time.h>
#include <map>
#include <set>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <string>
#include <fstream>
#include <assert.h>
#include <list>
#include <cstring>
#include <queue>

using namespace std;

#define name "pail"

typedef long long ll;

struct __isoff {
	__isoff() {
		if (_ijps)
			freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);//, freopen("test.txt", "w", stderr);
		//else freopen(name".in", "r", stdin), freopen(name".out", "w", stdout);
		//ios_base::sync_with_stdio(0);
		//srand(time(0));
		srand('C' + 'T' + 'A' + 'C' + 'Y' + 'M' + 'B' + 'A');
	}

	~__isoff() {
		//if(_ijps) cout<<times<<'\n';
	}
} __osafwf;

int main() {
	int n;
	cin >> n;
	deque<int> T;
	bool rev = false;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (i % 2) {
			T.push_back(t);
		}
		else {
			T.push_front(t);
		}
	}
	if (!(n % 2)) {
		reverse(T.begin(), T.end());
	}
	for (auto v : T) {
		cout << v << ' ';
	}
}
