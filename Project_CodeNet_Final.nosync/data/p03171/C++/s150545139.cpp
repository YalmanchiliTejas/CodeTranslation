#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<set>
#include<list>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<cstdio>
#include<iomanip>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, pii>;
const int INF = 1e9 + 7;
ll memo[3001][3001][2];
int a[3000];
//f(a,b,c)で左端がa,右端がbの時のX-Yを返す。c=0の時太郎の番1の時次郎の番
ll f(int l, int r, int state) {
	if (l > r)return 0;
	if (memo[l][r][state] !=0)return memo[l][r][state];
	ll ret = 0;
	if (state == 0) {
		ret = max(f(l + 1, r, 1) + a[l], f(l, r - 1, 1) + a[r]);
	}
	else {
		ret = min(f(l + 1, r, 0) - a[l], f(l, r - 1, 0) - a[r]);
	}
	return  memo[l][r][state] = ret;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cout << f(0, n - 1, 0) << endl;
	return 0;
}