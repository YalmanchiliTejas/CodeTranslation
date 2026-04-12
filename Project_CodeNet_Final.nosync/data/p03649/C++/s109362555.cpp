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
		r = std::max(0LL, (a[k]-n) / k - 2); // (a[n] - n)/k >= t
		if(k == 1) 
			l = r;
		else {
			while(l ^ r) {
				mid = (l + r + 1) >> 1;
				if(a[k - 1] + mid * (n - k + 1) <= a[k] - mid * k)
					l = mid;
				else
					r = mid - 1;
			}
		}
		
		if(l) {
			for(i = 1; i < k; i++) 
				a[i] += l * (n - k + 1);
			for(i = k; i <= n; i++)
				a[i] -= l * k;
			ans += l * (n - k + 1);
		}
		
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