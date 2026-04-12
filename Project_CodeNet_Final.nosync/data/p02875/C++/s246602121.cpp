#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e7 + 7;
const int MX = 998244353;
const LL INF = 1LL * MX * MX;

int n;
int rv[N];
int sil[N];

int fast(int a, int b){
	int ret = 1;
	while(b){
		if(b & 1)
			ret = (1LL * ret * a) % MX;
		
		b >>= 1;
		a = (1LL * a * a) % MX;
	}
	
	return ret;
}

inline int newton(int a, int b){
	return (((1LL * sil[a] * rv[b]) % MX) * rv[a - b]) % MX;
}

int main(){
	scanf("%d", &n);
	sil[0] = 1;
	for(int i = 1; i <= n; ++i)
		sil[i] = 1LL * i * sil[i - 1] % MX;
	
	rv[n] = fast(sil[n], MX - 2);
	for(int i = n; i >= 1; --i)
		rv[i - 1] = 1LL * i * rv[i] % MX;
	
	int cur = 1, ans = 0;
	for(int i = n; i + i > n; --i){
		ans = (ans + 1LL * cur * newton(n, i)) % MX;
		cur = (cur + cur) % MX;
	}

	ans = (ans + ans) % MX;
	ans = (fast(3, n) + MX - ans) % MX;
	printf("%d\n", ans);
	return 0;
}