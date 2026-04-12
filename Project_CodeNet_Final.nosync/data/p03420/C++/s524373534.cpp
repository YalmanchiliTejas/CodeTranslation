//ProblemD

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

//ProblemD

class Solve {
private:

	int n, k;
	void solve() {
		cin >> n >> k;

		unsigned long long rst = 0;
		for (int i = k + 1; i <= n; i++) {
			if (k == 0) rst += n;
			else {
				rst += n + 1;
				rst -= (n + 1) / i * k;

				if ((n + 1) % i > k) rst -= k;
				else rst -= (n + 1) % i;
			}
		}
		cout << rst << endl;
	}

public:
	Solve() { solve(); }
};

int main(int argc, char* argv[]) {
	unique_ptr<Solve> solve = make_unique<Solve>();
	return 0;
}
