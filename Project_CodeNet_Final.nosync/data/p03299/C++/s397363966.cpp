#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef pair <LL, LL> pii;
const LL MOD = 1000000007LL;
const int MAXN = 105, INF = 1000000001;

int n, h[MAXN];

inline LL mul(LL a, LL b){return a * b % MOD;}
inline LL quickPow(LL base, int times){
	LL ret = 1LL;
	while(times){
		if(times & 1) ret = ret * base % MOD;
		base = base * base % MOD;
		times >>= 1;
	} return ret;
}
pii solve(int l, int r, int b){
	int i, j, mn = INF; pii f, tmp;
	for(i = l; i <= r; ++ i)
		if(h[i] < mn) mn = h[i];
	for(i = l; i <= r; i = j + 1)
		if(h[i] > mn){
			for(j = i; j < r && h[j + 1] > mn; ++ j) ;
			tmp = solve(i, j, mn);
			if(i == l) f = pii(mul(tmp.first, 2), tmp.second);
			else f = pii(mul(mul(tmp.first, f.first), 2), (mul(mul(f.first, tmp.first), 4) + mul(mul(f.first, tmp.second), 2) + mul(mul(f.second, tmp.first), 4) + mul(f.second, tmp.second)) % MOD);
		}else{
			j = i;
			if(i == l) f = pii(1, 0);
			else f = pii(f.first, (f.first * 2 + f.second * 2) % MOD);
		}
	return pii(f.first * quickPow(2, mn - b - 1) % MOD, f.second);
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i)
		scanf("%d", &h[i]);
	auto ret = solve(1, n, 0);
	printf("%d\n", int((ret.first * 2 + ret.second) % MOD));
	return 0;
}