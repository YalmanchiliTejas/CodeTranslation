#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <climits>
#include <math.h>
#include <cassert>
#include <unordered_map>
#include <chrono>
#include <random>
#include <ctime>
using namespace std;
#pragma warning(disable : 4996)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ld PI = 3.14159265358979323846;
const ll MOD = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll INF = 1e16;



int main() {
#ifdef _DEBUG
	freopen("input1.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif
	srand(time(0));
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	cout << (n >= 30 ? "Yes" : "No");
}