#include <bits/stdc++.h>

typedef long long ll;
const int N = 200054;

int n;
int l[N], r[N], o[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline ll min(const ll x, const ll y) {return x < y ? x : y;}

int main() {
	int i, c, x, y, *li, *ls, *ri, *rs;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d%d", &x, &y), std::tie(l[i], r[i]) = std::minmax(x, y);
	std::tie(li, ls) = std::minmax_element(l, l + n),
	std::tie(ri, rs) = std::minmax_element(r, r + n),
	std::iota(o, o + (n + 1), 0), x = *ls, l[n] = c = y = INT_MAX,
	std::sort(o, o + n, [] (const int x, const int y) {return l[x] < l[y];});
	for (i = 0; i < n; ++i) up(x, o[i][r]), down(y, o[i][r]), down(c, x - min(y, o[i + 1][l]));
	printf("%lld\n", min(ll(*rs - *li) * c, ll(*ls - *li) * (*rs - *ri)));
	return 0;
}