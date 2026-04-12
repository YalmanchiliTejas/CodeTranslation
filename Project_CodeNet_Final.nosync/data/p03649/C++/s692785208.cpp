#include <cstdio>
#include <algorithm>

typedef long long int64;

const int MAXN = 50 + 10;

int n;
int64 a[MAXN];

inline int randint(int l, int r) {
	static unsigned seed;
	return (seed = (seed * 31 + 998244353) % 1000000007) % (r - l + 1) + l;
}

int main() {
	int i, k;
	int64 l, r, mid, ans = 0;
	
	scanf("%d", &n);
	for(i=1; i<=n; i++)
		scanf("%lld", &a[i]);
	
	std::sort(a+1, a+1+n);
	while(a[n] >= n) {
		k = n;
		while(k > 1 and a[n] - n < a[k - 1] + 1)
			k--;
		l = 0;
		r = (a[n]-n) / k + 1; // (a[n] - n)/k >= t
		while(l ^ r) {
			mid = (l + r + 1) >> 1;
			if((k == 1 or a[k - 1] + mid * (n - k + 1) <= a[k] - mid * k) and a[k] - mid * k >= n)
				l = mid;
			else
				r = mid - 1;
		}
		for(i = 1; i < k; i++) 
			a[i] += l * (n - k + 1);
		for(i = k; i <= n; i++)
			a[i] -= l * k;
		ans += l * (n - k + 1);
		
		k = randint(1, 5);
		while(k and a[n] >= n) {
			for(i = 1; i < n; i++)
				a[i]++;
			a[n] -= n;
			ans++;
			k--;
			std::sort(a+1, a+1+n);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
/*
42
100000000000 10000000000 10000000000 100000000000 10000000000 10000000000
10000000000 1000000000 1000000000 10000000000 1000000000 1000000000
50000000000 5000000000 5000000000 50000000000 5000000000 5000000000
5000000000 500000000 500000000 5000000000 500000000 500000000
500000000 50000000 50000000 500000000 50000000 50000000
50000000 5000000 5000000 50000000 5000000 5000000
5000000 500000 500000 5000000 500000 500000
100000000000 99999999999 99999999998 10293857 5232 5
*/