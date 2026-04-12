#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <set>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cstring>

using namespace std;
using ll = long long;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<double, double >pd;
typedef pair<string, string> sP;
typedef pair<ll, P> PP;
typedef pair<P, P> PPP;

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 1 << 30;
const ll INF2 = 9e18;
const double INF3 = 9e14;
const double eps = 1e-10;
const double PI = 3.14159265358979323846;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };

#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define pb push_back
#define eb emplace_back
#define fr first
#define sc second


struct Starry_Sky_tree {
private:
	vector<ll>segMin;
	vector<ll>segAdd;
	ll N;
public:
	Starry_Sky_tree(vector<ll>v) {
		ll sz = v.size();
		N = 1;while (N < sz)N *= 2;
		segMin.resize(2 * N - 1, 0);
		segAdd.resize(2 * N - 1, 0);
	}

	//区間[a, b)に値xを加算する.
	void add(int a, int b, int x, int k = 0, int l = 0, int r = -1)
	{
		if (r < 0)r = N;
		if (r <= a || b <= l) return; //もし交差しない区間であれば終える.

		if (a <= l && r <= b) { //もし今みている区間[l, r)が[a, b)に完全に内包されていれば
			segAdd[k] += x;  //区間[l, r)にkを加算する.
			return;
		}

		add(a, b, x, k * 2 + 1, l, (l + r) / 2); //子の区間に(必要があれば)xを加算する.
		add(a, b, x, k * 2 + 2, (l + r) / 2, r); //〃

												 //親の区間の最小値は, 子の区間の最小値 + 自分に一様に加算されている値 である.一様に加算される値は更新しなくて良い.
		segMin[k] = min(segMin[k * 2 + 1] + segAdd[k * 2 + 1], segMin[k * 2 + 2] + segAdd[k * 2 + 2]);
	}

	ll getMin(int a, int b, int k = 0, int l = 0, int r = -1)
	{
		if (r < 0)r = N;
		if (r <= a || b <= l) return INF2;

		if (a <= l && r <= b) return segMin[k] + segAdd[k]; //完全に内包されていれば,その区間の最小値を返す.

		ll left = getMin(a, b, k * 2 + 1, l, (l + r) / 2); //子の区間の最小値を求める.
		ll right = getMin(a, b, k * 2 + 2, (l + r) / 2, r); //子の区間の最小値を求める

		return min(left, right) + segAdd[k]; //親の区間の最小値は, 子の区間の最小値 + 自分に一様に加算されている値 である (大切なので2回書きました!!)

	}
};

vector<ll>v;

int main() {
	ll n, d[300010];
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> d[i];
	}
	v.resize(n+1);
	Starry_Sky_tree seg(v);
	seg.add(1, 2, 1);
	for (int i = 1;i < n;i++) {
		if (seg.getMin(i, i + 1) >= 1) {
			if (d[i] / 10 >= 1)seg.add(i + 1, min(n+1, i + d[i] / 10 + 1), 1);
		}
	}
	if (seg.getMin(n, n + 1) == 0) {
		cout << "no" << endl;
		return 0;
	}
	Starry_Sky_tree se(v);
	se.add(n, n + 1, 1);
	for (int i = n;i >= 2;i--) {
		if (se.getMin(i, i + 1) >= 1) {
			if (d[i] / 10 >= 1)se.add(max(1LL, i - d[i] / 10), i, 1);
		}
	}
	if (se.getMin(1, 2) == 0) {
		cout << "no" << endl;
		return 0;
	}
	cout << "yes" << endl;
	return 0;
}

