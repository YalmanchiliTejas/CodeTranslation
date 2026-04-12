#define _CRT_SECURE_NO_WARNINGS
#include <cassert>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
using namespace std;

#define int long long
#define pii pair<int, int>
#define ld long double

#define form(i, n) for (int i = 0; i < (n); ++i)
#define form2(i, a, b) for (int i = (a); i < (b); ++i)
#define ford(i, n) for (int i = (n-1); i >= 0; --i)
#define ford2(i, a, b) for (int i = (a-1); i >= (b); --i)

#define chmax(x, v) x = max(x, (v));

void solve();
signed main()
{
#ifdef LOCAL_HUGO
	freopen("in.txt", "r", stdin);
#else
	ios::sync_with_stdio(false);
	cin.tie(0);
#endif
	solve();
}

const int e2 = 18;
const int p2 = 1 << e2;
const int ph = 2 * p2;
const int inf = LLONG_MAX / 2LL;
int lazyadd[ph];
int segmax[ph];
pii inv[ph];

void build()
{
	form2(i, p2, ph) inv[i] = { i - p2, i - p2 };
	ford(i, p2) inv[i] = { inv[2 * i].first, inv[2 * i + 1].second };
}

void apply(int nod)
{
	segmax[nod] += lazyadd[nod];
	if (nod < p2) {
		lazyadd[2 * nod] += lazyadd[nod];
		lazyadd[2 * nod + 1] += lazyadd[nod];
	}
	lazyadd[nod] = 0;
}

int bg, bd, val;
void add(int nod)
{
	apply(nod);
	if (bd < inv[nod].first || inv[nod].second < bg) {}
	else if (bg <= inv[nod].first && inv[nod].second <= bd) { lazyadd[nod] += val; apply(nod); }
	else if (nod < p2) { add(2 * nod); add(2 * nod + 1); segmax[nod] = max(segmax[2 * nod], segmax[2 * nod + 1]); }
}

int gmax(int nod)
{
	apply(nod);
	if (bd < inv[nod].first || inv[nod].second < bg) { return -inf; }
	else if (bg <= inv[nod].first && inv[nod].second <= bd) { return segmax[nod]; }
	else if (nod < p2) { return max(gmax(2 * nod), gmax(2 * nod + 1)); }
	else { return -inf; }
}

void add2(int gauche, int droite, int valeur)
{
	bg = gauche;
	bd = droite;
	val = valeur;
	add(1);
}

int smax(int gauche, int droite)
{
	bg = gauche;
	bd = droite;
	return gmax(1);
}
const int borne = 2 * (int)(1e5) + 5;
int l[borne];
int r[borne];
int a[borne];
int n, k;
vector<int> al[borne];
vector<int> ar[borne];

void solve()
{
	build();
	cin >> n >> k;
	form(i, k)
	{
		cin >> l[i] >> r[i] >> a[i];
		al[l[i]].push_back(i);
		ar[r[i]+1].push_back(i);
	}

	int rep = 0;
	form2(i, 1, n+1)
	{
		for (int x : al[i]) {
			add2(0, l[x] - 1, a[x]);
		}
		for (int x : ar[i]) {
			add2(0, l[x] - 1, -a[x]);
		}
		int ss = smax(0, i - 1);
		chmax(rep, ss);
		add2(i, i, ss);
	}

	cout << rep << '\n';
}