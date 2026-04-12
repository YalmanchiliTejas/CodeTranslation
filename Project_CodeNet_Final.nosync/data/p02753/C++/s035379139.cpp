//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math") 
///#pragma GCC target("avx2")
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <iomanip>
#include <cassert>
#include <functional>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <climits>
#include <numeric>

using namespace std;
#define open_streams ifstream fin("olympiad.in");ofstream fout("olympiad.out")
#define close_streams fin.close();fout.close()
#define speed cout.tie(0);cin.tie(0);ios_base::sync_with_stdio(0)
#define ll long long
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define UNIQ(a) a.resize(unique(all(a)) - a.begin())
#define eps 1e-6
//const double PI = M_PI;
const int INF = INT_MAX;
const ll limit = 1LL * 4e18;
const int MOD = 1e9 + 711;
const int MOD2 = 1e9 + 933;
//---------------------------------------------------------------------------
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;






signed main() {
	speed;
	string s;
	cin >> s;
	if (s != "AAA" && s != "BBB") {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}