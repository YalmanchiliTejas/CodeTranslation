#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <functional>
#include <numeric>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }

int N, A[212345];

int main() {

	scanf("%d", &N);
	rep(i, N) scanf("%d", &A[i]);

	int ans = 0;
	multiset<int> cm;

	rep(i, N) {
		if (cm.upper_bound(-A[i]) == cm.end()) {
			cm.insert(-A[i]);
		}
		else {
			cm.erase(cm.upper_bound(-A[i]));
			cm.insert(-A[i]);			
		}
	}

	printf("%d\n", (int)cm.size());

	return 0;
}
