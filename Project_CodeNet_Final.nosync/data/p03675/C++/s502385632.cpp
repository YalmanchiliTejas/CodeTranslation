
/*
 _    _    _______   _    _
| |  / /  |  _____| | |  / /
| | / /   | |       | | / /
| |/ /    | |_____  | |/ /
| |\ \    |  _____| | |\ \
| | \ \   | |       | | \ \
| |  \ \  | |_____  | |  \ \
|_|   \_\ |_______| |_|   \_\

*/
/*#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <assert.h>*/

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;

#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define right(x) x << 1 | 1
#define left(x) x << 1
#define forn(x, a, b) for (int x = a; x <= b; ++x)
#define for1(x, a, b) for (int x = a; x >= b; --x)
#define mkp make_pair
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define y1 kekekek

const ll ool = 1e18 + 9;
const int oo = 1e9 + 9, base = 1e9 + 7;
const ld eps = 1e-7;
const int N = 2e6 + 6;

int n;
vector < int > vec[2];

int main() {
	ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	forn(i, 1, n) {
        int x;
        cin >> x;
        vec[i & 1].eb(x);
	}

	if (n & 1) swap(vec[0], vec[1]);
	reverse(all(vec[0]));
	for (auto it : vec[0]) cout << it << " ";
	for (auto it : vec[1]) cout << it << " ";

	return 0;
}
