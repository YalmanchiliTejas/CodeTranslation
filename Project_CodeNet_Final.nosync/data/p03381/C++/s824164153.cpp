//ProblemC

#ifdef _MYPC
#include "mypc.h"
#endif // _MYPC

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <functional>
#include <memory>
#include <complex>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

//ProblemC

class Solve {
private:

	void solve() {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		auto b = a;
		sort(b.begin(), b.end());

		for (int i = 0; i < n; i++) {
			if (a[i] < b[n/2]) {
				cout << b[n / 2] << endl;
			}
			else {
				cout << b[n / 2 - 1] << endl;
			}
		}

	}

public:
	Solve() { solve(); }
};

int main(int argc, char* argv[]) {
	unique_ptr<Solve> solve = make_unique<Solve>();
	return 0;
}
