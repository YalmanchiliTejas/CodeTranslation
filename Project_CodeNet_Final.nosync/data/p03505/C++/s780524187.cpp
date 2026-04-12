#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
using namespace std;

#define MP make_pair
#define PB push_back
#define ALL(s) (s).begin(),(s).end()
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl


long long K, A, B;


long long solve() {
	if (A >= K) return 1;
	if (A - B <= 0) return -1;

	long long rem = K - A;
	long long con = (rem + A-B - 1) / (A - B);
	return con * 2 + 1;
}

int main() {
	while (cin >> K >> A >> B) {
		cout << solve() << endl;
	}
}