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
#include<cstdio>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1e9;
ll mod = 1e9 + 7;
ll Len[55], Pat[55];//バーガーの厚さとパティの総数
ll rec(ll level, ll layer) {
	if (level == 0)return 1;
	if (layer == 1)return 0;
	else if (layer <= Len[level - 1] + 1) {
		return rec(level - 1, layer - 1);
	}
	else if (layer <= Len[level - 1] + 2) {
		return Pat[level - 1] + 1;
	}
	else if (layer <= 2 * Len[level - 1] + 2) {
		return Pat[level - 1] + 1 + rec(level - 1, layer - Len[level - 1] - 2);
	}
	else {
		return 2 * Pat[level - 1] + 1;
	}
}
//レベルNバーガーの下からX層に含まれるパティの総数をrec(N,X)とする
signed main() {
	ll N, X;
	cin >> N >> X;
	Len[0] = Pat[0] = 1;
	for (int i = 1; i <= N; ++i) {
		Len[i] = Len[i - 1] * 2 + 3;
		Pat[i] = Pat[i - 1] * 2 + 1;
	}
	cout << rec(N, X) << endl;
	return 0;
}