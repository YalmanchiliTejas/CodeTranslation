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
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define NREP(i, n) FOR(i, 1, n)
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, pii>;
const ll dx[4] = { 0, -1, 1, 0 };
const ll dy[4] = { -1, 0, 0, 1 };
const ll INF = 1e9 + 7;
const ll inf = 1LL << 50;
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return gcd(y, x%y);
}
void mul(ll a, ll b) {
	a = a * b % INF;
}
///////////////////////////////////////

int main() {
	int N; cin >> N;
	vector<int>A(N);
	REP(i, N)cin >> A[i];
	sort(A.begin(), A.end());
	deque<int>Q;
	for (int i = 1; i < N - 1; ++i) {
		Q.push_back(A[i]);
	}
	ll sum = 0;
	pii p;//両端を保存
	p.first = A[0];//左端
	p.second = A[N - 1];//右端
	sum += A[N - 1] - A[0];
	while (!Q.empty()) {
		int x = Q.front();
		int y = Q.back();
		int key1, key2, key3, key4;
		key1 = abs(x - p.first);
		key2 = abs(x - p.second);
		key3 = abs(y - p.first);
		key4 = abs(y - p.second);
		if (key1 >= key2 && key1 >= key3 && key1 >= key4) {
			sum += key1;
			Q.pop_front();
			p.first = x;
		}
		else if (key2 >= key1 && key2 >= key3 && key2 >= key4) {
			sum += key2;
			Q.pop_front();
			p.second = x;
		}
		else if (key3 >= key1 && key3 >= key2 && key3 >= key4) {
			sum += key3;
			Q.pop_back();
			p.first = y;
		}
		else {
			sum += key4;
			Q.pop_back();
			p.second = y;
		}
	}
	cout << sum << endl;
	return 0;
}