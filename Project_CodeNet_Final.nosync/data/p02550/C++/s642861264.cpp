// E - Sequence Sum
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rp(i,s,e) for(int i=(int)(s);i<(int)(e);++i)

int main(){
	ll n; int x, m; cin>>n>>x>>m;
	vector<pair<int,int>> P; // (x,pre_sum)
	ll sum_p = 0; // sum of pre + cycle
	vector<int> X(m, -1); // for cycle check & pre_len
	for(ll i=0; i<n; ++i){
		if(X[x] > -1){
			int cyc_len = P.size() - X[x];
			int nxt_len = (n - X[x]) % cyc_len;
			ll remain = P[X[x]].second;
			ll cyc = (sum_p - remain) * ((n - X[x]) / cyc_len);
			remain +=P[X[x]+nxt_len].second - P[X[x]].second;
			cout<< cyc + remain <<endl;
			return 0;
		}
		P.emplace_back(x, sum_p);
		sum_p += x;
		X[x] = i;
		x = (ll)x*x % m;
	}
	cout<< sum_p <<endl;
}
