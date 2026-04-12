#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1000000007;
LL powmod(LL a, LL n){
    if(n == 0) return 1;
    if(n % 2) return (a*powmod(a,n-1)) % MOD;
    LL c = powmod(a, n/2);
    return (c*c) % MOD;
}
LL inv(LL a){
    return powmod(a, MOD-2);
}
LL fact[110000];
LL invfact[110000];

LL ncr(LL n, LL r){
    if(r < 0 || n < 0) return 0;
    if(n < r) return 0;
    LL a = fact[n];
    a = (a * invfact[r]) % MOD;
    a = (a * invfact[n-r]) % MOD;
    return a;
}
void init(){
    fact[0] = 1;
    invfact[0] = 1;
    LL inv2 = inv(2);
    for(LL i = 1; i < 110000; i++){
        fact[i] = (i*fact[i-1]) % MOD;
        invfact[i] = inv(fact[i]);
    }
}

pair<LL,LL> solve(vector<LL> a){
	LL r = a[0];
	for(int j = 0; j < a.size(); j++){
		r = min(r, a[j]);
	}
	LL num0 = 0;
	for(int j = 0; j < a.size(); j++){
		a[j] -= r;
		if(a[j] == 0) num0++;
	}
	vector<LL> cur;
	LL total = powmod(2, num0);
	LL alternating = 2;
	a.push_back(0);

	for(int j = 0; j < a.size(); j++){
		if(a[j] == 0 && cur.size() > 0){
			pair<LL,LL> d = solve(cur);
			cur.clear();
			total = (total * (d.first + d.second) ) % MOD;
			alternating = (alternating * d.second) % MOD;
		}
		if(a[j] != 0){
			cur.push_back(a[j]);
		}
		if(a[j] == 0){
			num0 ++;
		}
	}
	total -= alternating;
	alternating = (alternating * powmod(2, r-1)) % MOD;
	total += alternating;
	total %= MOD;
	if(total < 0) total += MOD;
	if(alternating < 0) alternating += MOD;
	return {total, alternating};
}
int main(){
	LL N;
	cin >> N;
	vector<LL> h;
	for(int i = 0; i < N; i++){
		LL a;
		cin >> a;
		h.push_back(a);
	}
	pair<LL,LL> ans = solve(h);
	cout << ans.first << endl;
}
