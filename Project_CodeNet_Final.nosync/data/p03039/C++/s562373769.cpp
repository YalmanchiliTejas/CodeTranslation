#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
inline int fpow(int n, int p){
    int ans = 1, base = n;
    while(p){
        if(p & 1) ans = ans * base % mod;
        base = base * base % mod;
        p >>= 1;
    }
    return ans;
}
int n, m, k, ans = 1, chu = 1, cnt;
signed main(){
    scanf("%lld%lld%lld", &n, &m, &k);
    for(register int i = n * m - 2; i >= n * m - k + 1; --i) ans = ans * i % mod;
    for(register int i = k - 2; i >= 1; --i) chu = chu * i % mod;
    ans = (ans * fpow(chu, mod - 2)) % mod;
    for(register int d = 1; d < n; ++d){
    	int x = (n - d) * m, y = m;
    	cnt = (cnt + (x * y % mod) * d % mod) % mod;
	}
	for(register int d = 1; d < m; ++d){
		int x = (m - d) * n, y = n;
		cnt = (cnt + (x * y % mod) * d % mod) % mod;
	}
    printf("%lld\n", ans * cnt % mod);
    return 0;
}