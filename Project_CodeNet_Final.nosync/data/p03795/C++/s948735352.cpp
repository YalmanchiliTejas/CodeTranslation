#define MYDEBUG
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <queue>
#include <set>
#include <cstdio>
#include <unordered_map>

#ifdef MYDEBUG
#define debug(x) cout<<#x<<": "<<x<<endl
#else
#define debug(x)
#endif
#define ll long long
#define ull unsigned long long
#define eps 1e-14
#define all(x) x.begin(), x.end()
using namespace std;

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
	out << "[";
	size_t last = v.size() - 1;
	for (size_t i = 0; i < v.size(); ++i) {
		out << v[i];
		if (i != last)
			out << ",";
	}
	out << "]";
	return out;
}

void solve() {
	int n;
	cin >> n;
	cout << n * 800 - (n / 15) * 200 << endl;
}
int main() {
	solve();
	return 0;
}
