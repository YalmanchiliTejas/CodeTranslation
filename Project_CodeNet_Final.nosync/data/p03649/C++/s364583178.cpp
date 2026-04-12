#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int,int> PP;

/*
    freopen("input","r",stdin);
    freopen("output","w",stdout);
*/

int N;
ll L[50];

bool check(ll n) {
	ll c = 0;
	for (int i = 0;i < N;i++) {
		c += (L[i] + n) / (N + 1);
	}
	return c <= n;
}

bool check2(ll n) {
	ll c = 0;
	for (int i = 0;i < N;i++) {
		c += (L[i] + n) / (N + 1);
		ll rem = (L[i] + n) % (N + 1);
		if (rem >= N) return 0;
	}
	return c == n;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0;i < N;i++) cin >> L[i];
    ll s = 0, l = 1E18;
    bool ok = 1;
    for (int i = 0;i < N;i++) {
    	if (L[i] >= N) ok = 0;
    }
    if (ok) {
    	cout << 0 << endl;
    	return 0;
    }
    while (s + 1 < l) {
    	ll m = s + (l - s) / 2;
    	if (check(m)) l = m;
    	else s = m;
    }
    for (ll x = max(0LL, l - 1000);x <= l + 1000;x++) {
    	if (check2(x)) {
    		cout << x << endl;
    		return 0;
    	}
    }
    return 0;
}