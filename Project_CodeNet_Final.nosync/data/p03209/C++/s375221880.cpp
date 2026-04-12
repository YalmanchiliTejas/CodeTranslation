#pragma once
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <deque>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 10e9;
const int MAX_V = 201;

ll rec(ll x,ll allv, ll lev,ll n) {

	if (x <= n) return 0;
	if (x > allv - n) return lev;

	if (n == 1) {
		return x == 5 ? 3 : x - 1;
	}
	
	ll half = allv / 2;
	ll sum = 0;
	if (half < x) {

		sum += lev / 2 + 1;
		sum += rec(x - half - 1, allv - half - 2, lev / 2, n - 1);
	}
	else {

		sum += rec(x - 1, half - 1, lev / 2 , n - 1);

	}

	return sum;
}

ll all(int n) {
	if (n == 0) return 1;
	return 3 + all(n - 1) * 2;
}
void Christmas(){
	int n;
	ll x;
	cin >> n >> x;
	ll lev = 1;
	for (size_t i = 0; i < n; i++)
	{
		lev = lev * 2 + 1;
	}
	ll allv  = all(n);
	cout << rec(x,allv,lev ,n) << endl;
}
int main() {
	Christmas();
	return 0;
}

