#include <bits/stdc++.h>
typedef long long int LL;
using namespace std;
#define INF (1LL << 60)
#define ALL(x) (x).begin(),(x).end()
#define FOR(i,k,n) for(int i=(k);(i)<(n);(i)++)
#define REP(i,n) for(int i = 0;(i)<(n);(i)++)
#define REPR(i,n) for(int i = n; i >= 0; i--)
#define F first
#define S second

vector<LL> a;	//a[i]　レベルiバーガーの厚さ
vector<LL> p;	//p[i]　レベルiバーガーのパティの総数

LL f(int n, LL x) {	//レベルnバーガーの下からｘ層に含まれるパティの枚数
	if (n == 0) {
		return 1;
	}
	if (x == 1) {
		return 0;
	}
	if (1 < x && x < 2 + a[n - 1]) {
		return f(n - 1, x - 1);
	}
	if (x == 2 + a[n - 1]) {
		return p[n - 1] + 1;
	}
	if (2 + a[n - 1] < x && x < 3 + a[n - 1] * 2) {
		return f(n - 1, x - (a[n - 1] + 2)) + p[n - 1] + 1;
	}
	if (x == 3 + a[n - 1] * 2) {
		return 2 * p[n - 1] + 1;
	}
}

int main() {
	LL n, x;
	cin >> n >> x;

	a.push_back(1);
	p.push_back(1);
	REP(i, n) {
		a.push_back(a[i] * 2 + 3);
		p.push_back(p[i] * 2 + 1);
	}

	cout << f(n, x) << endl;
	return 0;
}
