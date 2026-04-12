#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <iomanip>
#include <bitset>
#include <unordered_map>
#include <stack>
#include <memory.h>
#include <list>
#include <numeric>
#include <functional>
#include <complex>
#include <cassert>
#include <regex>
#include <random>

#define ll long long
#define ld long double
#define ull unsigned ll
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pii pair<int,int> 
#define vi vector<int>
#define vpii vector<pii>
#define vvi vector<vector<int>>
#define forn(it,from,to) for(int (it)=from; (it)<to; (it)++)
const int  Inf = 2 * 1000 * 1000 * 1000;
ll LINF = (ll)4e18;
using namespace std;
#define M_PI       3.14159265358979323846   // pi


int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int>a(n);
	vector<int>mx(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i) mx[i] = mx[i - 1];
		mx[i] = max(mx[i], a[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= mx[i]) ans++;
	}
	cout << ans;
 	return 0;
}