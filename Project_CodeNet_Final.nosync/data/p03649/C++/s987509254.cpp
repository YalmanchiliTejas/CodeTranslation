#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <deque>
using namespace std;
 
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ppb pop_back
#define ll long long
#define ull unsigned long long
#define cntbit(x) __builtin_popcount(x)
#define endl '\n'
#define uset unordered_set
#define umap unordered_map
#define pii pair<int, int>
#define ld long double
#define pll pair<long long, long long>
 
const int inf = 2e9;
const int N = 55;
ll n, a[N], ans;

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	while(1) {
		int ind = 1;
		for(int i = 1; i <= n; ++i)
			if(a[ind] < a[i])
				ind = i;
		if(a[ind] < n)
			break;
		ll val = a[ind] / n;
		ans += a[ind] / n;
		a[ind] -= (a[ind] / n) * n;
		for(int i = 1; i <= n; ++i)
			if(i != ind)
				a[i] += val;
	}
	cout << ans << endl;
	return 0;
}