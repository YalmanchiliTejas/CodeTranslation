#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <map>
#include <set>
#include <chrono>
#include <queue>
#include <string>
#include <cassert>
#include <bitset>
#include <stack> 
#include <unordered_set>

#define INFLL 2000000000000000000
#define INF 2000000000
#define MOD 1000000007
#define BASE 77747
#define PI acos(-1.0)
#define MAXLEN 29

using namespace std;

typedef pair <int, int> pii;
typedef long long ll;
typedef vector <ll> vll;

int n, m;
pair <ll, ll> t[800000];
pii arr[200000];

void add(int v, int l, int r, int wl, int wr, ll val) {
	if (wl > wr) return;
	if (wl == l && wr == r) {
		t[v].second += val;
		t[v].first += val;
		return;
	}
	int mid = (l + r) / 2;
	add(2 * v, l, mid, wl, min(mid, wr), val);
	add(2 * v + 1, mid + 1, r, max(mid + 1, wl), wr, val);
	t[v].first = max(t[2 * v].first, t[2 * v + 1].first) + t[v].second;
}

void setValue(int v, int l, int r, int index, ll val) {
	if (l == r) {
		t[v].first = val + t[v].second;
		return;
	}
	int mid = (l + r) / 2;
	if (index <= mid) setValue(2 * v, l, mid, index, val);
	else setValue(2 * v + 1, mid + 1, r, index, val);
	t[v].first = max(t[2 * v].first, t[2 * v + 1].first) + t[v].second;
}
ll getMax(int v, int l, int r, int wl, int wr) {
	if (wl > wr) return -INFLL;
	if (wl == l && wr == r) return t[v].first;
	int mid = (l + r) / 2;
	ll le = getMax(2 * v, l, mid, wl, min(mid, wr));
	ll ri = getMax(2 * v + 1, mid + 1, r, max(wl, mid + 1), wr);
	return max(le, ri) + t[v].second;
}

struct Point {
	int val;
	ll pp;
	bool isEnd;
	int ind;
};

Point all[400000];

bool cmp(Point a, Point b) {
	if (a.val != b.val) return a.val < b.val;
	if (a.isEnd != b.isEnd) return !a.isEnd;
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		ll pp;
		scanf("%d %d %lld", &arr[i].first, &arr[i].second, &pp);
		arr[i].first--;
		arr[i].second--;

		all[2 * i].val = arr[i].first;
		all[2 * i].isEnd = false;
		all[2 * i].ind = i;
		all[2 * i].pp = pp;
		all[2 * i + 1].val = arr[i].second;
		all[2 * i + 1].isEnd = true;
		all[2 * i + 1].ind = i;
		all[2 * i + 1].pp = pp;
	}
	sort(all, all + 2 * m, cmp);
	// for (int i = 0; i < 2 * m; i++) {
	// 	cout << all[i].val << " " << all[i].ind << " " << all[i].pp;
	// 	cout << " " << all[i].isEnd << endl;
	// }
	int index = 0;
	ll cur = 0;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		while (index < 2 * m  && i == all[index].val && !all[index].isEnd) {
			cur += all[index].pp;
			add(1, 0, n - 1, arr[all[index].ind].first, arr[all[index].ind].second, -all[index].pp);
			index++;
		}
		ll cc = max(0LL, getMax(1, 0, n - 1, 0, i - 1)) + cur;
		setValue(1, 0, n - 1, i, cc);
		ans = max(ans, cc);
		while (index < 2 * m  && i == all[index].val) {
			cur -= all[index].pp;
			add(1, 0, n - 1, arr[all[index].ind].first, arr[all[index].ind].second, all[index].pp);
			index++;
		}
	}
	cout << ans << endl;
	return 0;
}