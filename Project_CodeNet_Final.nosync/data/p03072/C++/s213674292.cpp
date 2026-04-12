#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <numeric>
#include <cassert>

using namespace std;
using ll = long long;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define nl "\n"

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int x[n];
	for(int i = 0; i < n; i++) {
		cin >> x[i];
	}
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		bool ans = true;
		for(int j = 0; j < i; j++) {
			if(x[j] > x[i]) {
				ans = false;
			}
		}
		if(ans) {
			cnt++;
		}
	}
	cout << cnt << nl;
}