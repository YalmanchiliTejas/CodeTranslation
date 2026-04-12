#include <algorithm>
#include <climits>
#include <cmath>
#include <complex>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef pair<int, int> i_i;
typedef double D;
typedef complex<D> P;
typedef long long ll;
D pi = acos(-1.0);

#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define rep1(i, N) for (int i = 1; i <= (int)N; i++)
#define pb push_back

const int MAX_N = 100010;
int _k, _N, _rank[MAX_N + 1], tmp[MAX_N + 1], sa[MAX_N + 1], lcp[MAX_N];

bool compare_sa(int i, int j) {
	if (_rank[i] != _rank[j]) return _rank[i] < _rank[j];
	else {
		int ri = i + _k <= _N ? _rank[i + _k] : -1;
		int rj = j + _k <= _N ? _rank[j + _k] : -1;
		return ri < rj;
	}
}

void make_sa(string s) {
	_N = s.length();
	rep(i, _N + 1) {
		sa[i] = i;
		_rank[i] = i < _N ? s[i] : -1;
	}
	for (_k = 1; _k <= _N; _k *= 2) {
		sort(sa, sa + _N + 1, compare_sa);
		tmp[sa[0]] = 0;
		rep1(i, _N)
			tmp[sa[i]] = tmp[sa[i - 1]] + (compare_sa(sa[i - 1], sa[i]) ? 1 : 0);
		rep(i, _N + 1) _rank[i] = tmp[i];
	}
}

void make_lcp(string s) {
	int N = s.length();
	rep(i, N + 1) _rank[sa[i]] = i;
	int h = 0;
	lcp[0] = 0;
	rep(i, N) {
		int j = sa[_rank[i] - 1];
		if (h > 0) h--;
		for (; j + h < N && i + h < N; h++)
			if (s[j + h] != s[i + h])
				break;
		lcp[_rank[i] - 1] = h;
	}
}

char c[2000001];

struct bit {
	vector<ll> v;
	bit(int n) : v(n + 1) {}
	ll sum(int i) {
		ll res = 0;
		for (; i > 0; i -= i & -i) res += v[i];
		return res;
	}
	void add(int i, ll x) {
		for (i++; i < v.size(); i += i & -i) v[i] += x;
	}
	ll sum(int i, int j) {
		return sum(j) - sum(i);
	}
};

int main() {
	string S; cin >> S;
	int N = S.length();
	make_sa(S);
	int Q; cin >> Q;
	vector<vector<pair<int, i_i> > > v(N + 1);
	for (int k = 0; k < Q; k++) {
		int l, r; scanf("%d%d%s", &l, &r, c);
		r++;
		string s = c;
		int n = s.length();
		int lb = -1, ub = N + 1;
		while (ub - lb > 1) {
			int mid = (lb + ub) / 2, i = sa[mid];
			if (S.substr(i, min(n, N - i)) >= s) ub = mid;
			else lb = mid;
		}
		int lb2 = -1, ub2 = N + 1;
		while (ub2 - lb2 > 1) {
			int mid2 = (lb2 + ub2) / 2, i = sa[mid2];
			if (S.substr(i, min(n, N - i)) > s) ub2 = mid2;
			else lb2 = mid2;
		}
		v[l].push_back(make_pair(k, i_i(ub, ub2)));
		v[max(l, r - n + 1)].push_back(make_pair(k, i_i(ub, ub2)));

	}
	bit bt(N + 1);
	vector<vector<int> > ans(Q);
	vector<int> sai(N + 1);
	for (int x = 0; x <= N; x++)
		sai[sa[x]] = x;
	for (int i = N; i >= 0; i--) {
		bt.add(sai[i], 1);
		for (int j = 0; j < v[i].size(); j++) {
			int k = v[i][j].first;
			int l = v[i][j].second.first, r = v[i][j].second.second;
			ans[k].push_back(bt.sum(l, r));
		}
	}
	for (int k = 0; k < Q; k++)
		printf("%d\n", abs(ans[k][0] - ans[k][1]));
}