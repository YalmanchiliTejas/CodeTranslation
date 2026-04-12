#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iomanip>
#include <queue>
using namespace std;

typedef int64_t ll;
const ll INF = 1000000000000000000;
#define fori(i, a, b) for (ll i = (a); i < (b); ++i)
#define ford(i, a, b) for (ll i = (b - 1); (a) <= i; --i)
#define rep(i, n) fori(i, 0, n)
#define vll vector<ll>
#define all(v) v.begin(), v.end()




int main() {
	ll x;
	cin >> x;
	if (x == 7 || x == 5 || x == 3) cout << "YES" << endl;
	else cout << "NO" << endl;
}
