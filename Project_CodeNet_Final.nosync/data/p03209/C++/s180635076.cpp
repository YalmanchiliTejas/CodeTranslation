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
ll N;
ll X;//def(a,b)でレベルaバーガーの下からb層に含まれるパティの枚数
ll a[55];//レベルiバーガーの厚さをai
ll p[55];//レベルiバーガーに含まれるパティの総数
ll def(ll x, ll y) {
	if (x == 0)return 1;
	if (y == 1)return 0;
	else if (y <= a[x - 1]+1) { 
		return def(x - 1, y - 1);
	}
	else if (y == a[x - 1] + 2) {
		return p[x - 1] + 1;
	}
	else if (y <= 2 * a[x - 1] + 2) {
		return p[x - 1] + 1 + def(x - 1, y - a[x - 1] - 2);
	}
	else {
		return 2 * p[x - 1] + 1;
	}
}
int main() {
	cin >> N >> X;
	a[0] = 1;
	p[0] = 1;
	for (int i = 0; i < N; ++i) {
		a[i + 1] = 2 * a[i] + 3;
		p[i + 1] = 2*p[i] + 1;
	}
	cout << def(N, X) << endl;
	return 0;
}