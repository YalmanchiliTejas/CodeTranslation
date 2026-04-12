#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <tuple>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <random>
#include <queue>
#include <deque>
#include <iterator>
#include <map>
#include <functional>
#include <numeric>
using namespace std;
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define pb(a) push_back(a)
#define llong long long
#define INF 1145141919
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;
int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };
template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }

int main() {
	int n;
	cin >> n;
	if (n == 3 || n == 5 || n == 7) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}
