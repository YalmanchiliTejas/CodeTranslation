#include <iostream>
#include <cstdio>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <stdlib.h>
#include <functional>
#include <string>
#include <list>
#include <fstream>
#include <iomanip>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) <= (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define MODU 1000000007
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
#define pritnf printf
#define scnaf scanf
#define itn int

#include <nmmintrin.h>
#ifdef _MSC_VER

#define __builtin_popcount _mm_popcnt_u32
#define __builtin_popcountll _mm_popcnt_u64
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*)array, (T*)(array + N), val);
}

struct Edge {
	int from, to;
};
struct RLAQ {
	ll sst[1 << 18];
	ll adt[1 << 18];
	RLAQ() {
		fill(sst, sst + (1 << 18), 0);
		fill(adt, adt + (1 << 18), 0);
	}
	void add(int p, int q, ll x, int k = 0, int l = 0, int r = (1 << 17)) {
		if (r <= p || q <= l) return;
		if (p <= l && r <= q) {
			adt[k] += x;
			return;
		}
		add(p, q, x, 2 * k + 1, l, (l + r) / 2);
		add(p, q, x, 2 * k + 2, (l + r) / 2, r);
		sst[k] = max(sst[2 * k + 1] + adt[2 * k + 1], sst[2 * k + 2] + adt[2 * k + 2]);
	}
	ll find(int p, int q, int k = 0, int l = 0, int r = (1 << 17)) {
		if (r <= p || q <= l) return LLONG_MIN / 2;
		if (p <= l && r <= q) return sst[k] + adt[k];
		ll m1, m2;
		m1 = find(p, q, 2 * k + 1, l, (l + r) / 2);
		m2 = find(p, q, 2 * k + 2, (l + r) / 2, r);
		return max(m1, m2) + adt[k];
	}
};

int arr[1000001], pc;
void Eratosthenes(int N) {//Nまでの素数表
	for (int i = 0; i < N; i++) {
		arr[i] = 1;
	}
	for (int i = 2; i < sqrt(N); i++) {
		if (arr[i]) {
			for (int j = i * 2; j <= N; j += i) {
				arr[j] = 0;
			}
		}
	}

	int cou = 0;
	for (int i = 2; i < N; i++) {
		if (arr[i] == 1) {
			arr[cou] = i;
			cou++;
		}
	}
	pc = cou;
}
int main() {

	int n, k;
	cin >> n >> k;
	ll ans = 0;
	rep(b, k + 1, n + 1) {

		ll lbm = k,rbm = b-1;
		ll cy = ((n - rbm) / b) + 1;
		ans += cy * (rbm - lbm + 1);

		ans += max(0LL,n - (cy * b + lbm) + 1);
		if (lbm == 0)
			ans--;

	}

	cout << ans << endl;

	return 0;
}