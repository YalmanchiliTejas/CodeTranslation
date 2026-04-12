#include <bits/stdc++.h>
#define LL long long
#define FOR(i,c) for(__typeof(c.begin()) i = c.begin(); i != c.end(); i++)
#define F first
#define S second
using namespace std;

const LL mod = 1e9 + 7;

template<typename T> T gcd(T a, T b) { return b == 0?a: gcd(b, a % b); }
template<typename T> T LCM(T a, T b) { return a*(b/gcd(a, b)); }
template<typename T> T expo(T base, T e, T mod) { T res = 1;
  while(e > 0) { if(e&1) res = res * base % mod; base = base * base % mod; e >>= 1; }
  return res;
}
template<typename T, typename S> T expo(T b, S e){if(e <= 1)return e == 0?1: b;\
	return (e&1) == 0?expo((b*b), e>>1): (b*expo((b*b), e>>1));}
template<typename T, typename S> T modinv(T a, S mod) { return expo(a, mod-2, mod); }
template<class T, class S> std::ostream& operator<<(std::ostream &os, const std::pair<T, S> &t) {
	os<<"("<<t.first<<", "<<t.second<<")";
	return os;
}
template<class T> std::ostream& operator<<(std::ostream &os, const std::vector<T> &t) {
	os<<"["; FOR(it,t) { if(it != t.begin()) os<<", "; os<<*it; } os<<"]";
	return os;
}
#define gc getchar
template <typename T> void in(T &x) {
	T c = gc(); while(((c < 48) || (c > 57)) && (c!='-')) c = gc();
	bool neg = false; if(c == '-') neg = true; x = 0; for(;c < 48 || c > 57;c=gc());
	for(;c > 47 && c < 58;c=gc())	x = (x*10) + (c - 48); if(neg)	x = -x;
}

const int MAXN = 2e5 + 100;
const LL INF = 1e18;

int n;

struct point {
	LL idx, x, y;
	bool operator<(const point &other) const {
		return x > other.x;
	}
} arr[MAXN];

int main() {
	in(n);
	if(n == 1) {
		puts("0");
		return 0;
	}
	int min_idx = -1, max_idx = -1;
	LL minim, maxim;
	for(int i = 1; i <= n; i++) {
		in(arr[i].x), in(arr[i].y);
		if(arr[i].x > arr[i].y) swap(arr[i].x, arr[i].y);
		if(i == 1) {
			minim = arr[1].x, maxim = arr[1].y;
		} else {
			minim = min(minim, arr[i].x), maxim = max(maxim, arr[i].y);
		}
	}
	for(int i = 1; i <= n; i++) {
		if(arr[i].x == minim && min_idx == -1) {
			min_idx = i;
		}
		if(arr[i].y == maxim) {
			max_idx = i;
		}
	}
	assert(max_idx != -1 && min_idx != -1);
	LL res = INF, x = -INF, y = INF;
	for(int i = 1; i <= n; i++) {
		if(max_idx == min_idx && i == min_idx) {
		} else if(max_idx == i) {
			x = max(x, arr[i].x);
		} else if(min_idx == i) {
			y = min(y, arr[i].y);
		} else {
			x = max(x, arr[i].x);
			y = min(y, arr[i].y);
		}
	}
	assert(x != -INF && y != INF);
	res = (maxim - y) * (x - minim);
	if(min_idx != max_idx) {
		y = arr[min_idx].y;
		x = arr[max_idx].x;
		if(y < x) swap(x, y);
		vector<point> pts;
		for(int i = 1; i <= n; i++) {
			if(arr[i].x > y) {
				y = arr[i].x;
			} else if(arr[i].y < x) {
				x = arr[i].y;
			}
		}
		for(int i = 1; i <= n; i++) {
			if(arr[i].x >= x && arr[i].x <= y) {
			} else if(arr[i].y >= x && arr[i].y <= y) {
			} else {
				assert(i != min_idx && i != max_idx);
				pts.push_back(arr[i]);
			}
		}
		sort(pts.begin(), pts.end());
		LL a = maxim - minim, b = INF;
		if(pts.size()) {
			multiset<LL> yss;
			for(auto &elem: pts) {
				yss.insert(elem.y);
			}
			yss.insert(y);
			b = min(b, (*yss.rbegin()) - x);
			for(int i = 0; i < pts.size(); i++) {
				yss.erase(yss.find(pts[i].y));
				b = min(b, (*yss.rbegin()) - pts[i].x);
			}
		} else {
			b = y - x;
		}
		res = min(res, a * b);
	}
	printf("%lld\n", res);
	return 0;
}
