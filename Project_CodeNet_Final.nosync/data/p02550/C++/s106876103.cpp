// E - Sequence Sum
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rp(i,s,e) for(int i=(int)(s);i<(int)(e);++i)

int main(){
	ll n; int x, m; cin>>n>>x>>m;
	vector<int> P; // value of pre & cycle
	ll sum_p = 0; // sum of pre + cycle
	vector<int> X(m, -1); // for cycle check & pre_len
	for(ll i=0; i<n; ++i){
		if(X[x] > -1){
			int cyc_len = P.size() - X[x];
			int nxt_len = (n - X[x]) % cyc_len;
			ll remain = 0; 
			rp(i, 0, X[x]) remain += P[i];
			ll cyc = (sum_p - remain) * ((n - X[x]) / cyc_len);
			rp(i, X[x], X[x] + nxt_len) remain += P[i];
			cout<< cyc + remain <<endl;
			return 0;
		}
		X[x] = i;
		P.push_back(x);
		sum_p += x;
		x = (ll)x*x % m;
	}
	cout<< sum_p <<endl;
}
