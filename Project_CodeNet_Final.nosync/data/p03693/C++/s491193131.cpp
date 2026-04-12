#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <numeric>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll inf = (ll)1e9;
const ll mod = (ll)1e9 + 7;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

int main()
{
	int r, g, b;
	cin >> r >> g >> b;

	cout << ((10 * g + b) % 4 == 0 ? "YES" : "NO") << endl;

}