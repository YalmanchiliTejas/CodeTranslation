#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<sstream>
#include<iomanip>
#include<limits>
#include<deque>
#include<map>
#include<list>
#include<set>
#include <unordered_set>
#include<vector>
#include<cmath>
#include<cstdio>
#include<memory>
#include<bitset>
#include <functional>
#include <queue>

using namespace std;

#define MOD 1000000007
#define INF 1050000000

int main() {
	int n; cin >> n;
	int h[n];
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	int m = h[0];
	int ans = 1;
	for (int i = 1; i < n; i++) {
		if (m <= h[i]) {
			m = h[i];
			ans++;
		}
	}

	cout << ans << endl;





}