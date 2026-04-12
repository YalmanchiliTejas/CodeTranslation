#include <bits/stdc++.h>
using namespace std;
const int mod = 1'000'000'007;
int mul(long long a, long long b){
	return a * b % mod;
}
int xp(long long a, long long b){
	a %= mod;
	int r = 1;
	for(; b; b >>= 1, a = mul(a, a)) if(b&1) r = mul(r, a);
	return r;
}
using pii = pair<int,int>;
pii solve(vector<int> f){
	int h = *min_element(f.begin(), f.end());
	vector<pii> sub;
	vector<int> smp;
	int miss = 0;
	for(int v : f){
		if(v > h){
			smp.push_back(v - h);
		} else {
			miss++;
			if(!smp.empty()){
				sub.push_back(solve(smp));
			}
			smp.clear();
		}
	}
	if(!smp.empty()) sub.push_back(solve(smp));
	pii now = {1, 1};
	for(pii p : sub) now.first = mul(now.first, p.first);
	for(pii p : sub) now.second = mul(now.second, p.first + p.second);
	now.second = mul(now.second, xp(2, miss));
	now.second += mod - mul(2, now.first); if(now.second >= mod) now.second -= mod;
	now.first = mul(now.first, xp(2, h));
	now.second += now.first; if(now.second >= mod) now.second -= mod;
	return now;
}
int main(){
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	cout << solve(a).second << endl;
	return 0;
}
