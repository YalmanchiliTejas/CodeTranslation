#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <ctime>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <fstream>
using namespace std;
#define fname ""
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define inf 1000000000
#define INF 1000000000000000000ll
const int N = 50;
ll a[N];
int n;

int main() {
	cin >> n;

	for (int i = 1; i <= n; ++ i) {
		cin >> a[i];
	}

	ll ans = 0;

	while (1) {
		int id = 1;
		for (int i = 2; i <= n; ++ i){
			if (a[id] < a[i]) id = i;
		}
		if (a[id] < n) break;
		ll need = a[id] / n;
		a[id] %= n;
		ans += need;

		for (int i = 1; i <= n; ++ i) {
			if (i != id) a[i] += need;
		}
	}

	cout << ans;

    return 0;
}
