#include <bits/stdc++.h>

#define DEBUG(...) fprintf(stderr,__VA_ARGS__)
#define clr(x) memset(x,0,sizeof x)
#define RG register

#define px first
#define py second

using std :: max;
using std :: min;
using std :: pair;
using std :: make_pair;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;

static const int INF = 1 << 30;
static const LL oo = 1LL << 60;
static const int maxm = 1e5 + 10;
static const LL mod = 1e9 + 7;

template <class T> inline bool chkmax(T &x, T y) {
    return x < y ? x = y,true : false;
}

template <class T> inline bool chkmin(T &x, T y) {
    return x > y ? x = y,true : false;
}

template <class T> inline void read (T &in) {
    in = 0; char ch = getchar(); T f = 1;
    for (;ch > '9' || ch < '0';ch = getchar()) if (ch == '-') f = -1;
    for (;ch >= '0' && ch <= '9';ch = getchar()) in = in * 10 + ch - '0';
    in = in * f;
}

LL prm[maxm],sig[maxm],ddf[maxm],pre[maxm];
int npr[maxm],ind[maxm],e[maxm];
LL n,K,ans;

LL fpm(LL x,LL k) {
	LL res = 1;
	while(k) {
		if(k & 1) res = res * x % mod;
		x = x * x % mod;
		k >>= 1;
	}
	return res;
}

void getPrime(int N) {
	sig[1] = 1,e[1] = 0;
	for(int i = 2;i <= N;i++) {
		if(!npr[i]) prm[++prm[0]] = i,sig[i] = 2,e[i] = 1;
		for(int j = 1;j <= prm[0] && 1LL * i * prm[j] <= N;j++) {
			npr[1LL * i * prm[j]] = 1;
			if(i % prm[j] == 0) {
				sig[i * prm[j]] = sig[i] / (e[i] + 1) * (e[i] + 2);
				e[i * prm[j]] = e[i] + 1;
				break;
			}
			sig[i * prm[j]] = sig[i] * sig[prm[j]];
			e[i * prm[j]] = 1;
		}
	}
	for(int i = 1;i <= N;i++) pre[i] = pre[i - 1] + sig[i];
}

int main() {

	read(n); read(K);

/*	
	for(int r = K;r <= n;r++) {
		for(int b = r + 1;b <= n;b++) {
			if(r) ans += (n - r) / b + 1;
			else ans += (n - r) / b;
		}
	}
*/

	for(LL r = K;r <= n;r++) {
		for(LL b = r + 1, nxt = 0;b <= n;b = nxt + 1) {
			if(n - r >= b) {
				nxt = min(n, (n - r) / ((n - r) / b));
				LL num = (n - r) / b + (r != 0);
				ans += 1LL * num * (nxt - b + 1);
			} else {
				ans += (n - b + 1);
				break;
			}
		}
	}
	
	printf("%lld\n", ans);

	return 0;
}
