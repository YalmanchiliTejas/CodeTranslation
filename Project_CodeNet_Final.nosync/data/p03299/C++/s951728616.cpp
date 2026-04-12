#include <bits/stdc++.h>

typedef long long int int64;
static const int64 mod = 1000000007LL;

int64 pow2(int x)
{	
	int64 val = 1;
	for(int i = 30;i >= 0;--i) {
		val = val * val % mod;
		if(((x >> i) & 1) == 1) {
			val = val * 2 % mod;
		}
	}
	return val;
}

std::pair<int64,int64> solve(std::vector<int> h)
{
	if(h.empty()) return std::make_pair(1,1);
	int min = h[0];
	for(int i = 1;i < h.size();++i) if(h[i] < min) min = h[i];
	std::vector<int> cur;
	int64 v1 = 1, v2 = 1;
	int w = 0;
	for(int i = 0;i <= h.size();++i) {
		if(i == h.size() || h[i] == min) {
			if(!cur.empty()) {
				std::pair<int64,int64> res = solve(cur);
				v1 = v1 * res.first % mod;
				v2 = v2 * (res.first + res.second) % mod;
				cur.clear();
			}
			++w;
		} else {	
			cur.push_back(h[i] - min);
		}
	}
	--w;
	return std::make_pair(v1*pow2(min)%mod, (v2*pow2(w)+(pow2(min)-2)*v1)%mod);
}

int main()
{
	int n;
	std::vector<int> h;
	scanf("%d",&n);
	for(int i = 0;i < n;++i) {
		int k;
		scanf("%d",&k);
		h.push_back(k);
	}
	std::pair<int64,int64> ans = solve(h);
	printf("%lld\n", ans.second);
}
