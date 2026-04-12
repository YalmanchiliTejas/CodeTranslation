/*
* @Author: wxyww
* @Date: 2020-03-23 07:30:09
* @Last Modified time: 2020-03-23 08:24:37
*/
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstring>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
#define int ll
const int N = 1010,mod = 1e9 + 7;
ll read() {
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,h[N];
int qm(int x,int y) {
	int ret = 1;
	for(;y;y >>= 1,x = 1ll * x * x % mod)
		if(y & 1) ret = 1ll * ret * x % mod;
	return ret;
}
#define pi pair<ll,ll>

pi solve(int l,int r,int lim) {
	int mn = 1e9,cnt = 0;pi ret;
	for(int i = l;i <= r;++i) {
		if(h[i] < mn) {
			mn = h[i];cnt = 1;
		}
		else if(h[i] == mn) cnt++;
	}
	if(cnt == r - l + 1) {
		ret.first = (qm(2,r - l + 1) - 2 + mod) % mod;
		ret.second = qm(2,mn - lim - 1);
		return ret;
	}
	int len = r - l + 1,s0 = 1,s1 = 1,lst = 0;
	for(int i = l;i <= r + 1;++i) {
		if(!lst && h[i] > mn) lst = i;
		else if(lst && (h[i] <= mn || i > r)) {
			len -= i - lst;
			pi tmp = solve(lst,i - 1,mn);
			s0 = 1ll * s0 * (tmp.first + 4ll * tmp.second % mod) % mod;
			s1 = 1ll * s1 * (2ll * tmp.second % mod) % mod;
			lst = 0;
		}
	}
	s0 = (s0 - s1 + mod) % mod;
	ret.first = 1ll * s0 * qm(2,len) % mod;
	ret.first += 1ll * s1 * (qm(2,len) - 2 + mod) % mod;
	ret.second = s1 * qm(2,mn - lim - 1) % mod;
	return ret;
}

 main() {
	n = read();
	for(int i = 1;i <= n;++i) h[i] = read();
	for(int i = 1;i <= 100000;++i) 
	if(n == 1) {
		printf("%d\n",qm(2,h[1]));
		return 0;
	}
	int ans = 1;
	for(int i = 1;i <= n;++i) {
		if(h[i] > h[i - 1] && h[i] > h[i + 1]) {
			ans = 1ll * ans * qm(2,h[i] - max(h[i - 1],h[i + 1])) % mod;
			h[i] = max(h[i - 1],h[i + 1]);
		}
	}

	pi ret = solve(1,n,0);
	printf("%lld",1ll * ans * (ret.first + ret.second + ret.second) % mod);

	return 0;
}