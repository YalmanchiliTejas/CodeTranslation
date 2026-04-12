// E - Sequence Sum
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
	ll n; int x, m; cin>>n>>x>>m;
	int mn = min(n, (ll)m);
	vector<int> P; // value of pre & cycle
	ll sum_p = 0; // sum of pre + cycle
	vector<bool> X(m, false); // for cycle check
	rep(_i, mn){
		if(X[x]){
			int pre_len = find(P.begin(), P.end(), x) - P.begin();
			int cyc_len = P.size() - pre_len;
			int nxt_len = (n - pre_len) % cyc_len;
			ll remain = 0; rep(i, pre_len + nxt_len) remain += P[i];
			ll cyc = sum_p; rep(i, pre_len) cyc -= P[i];
			cyc *= (n - pre_len) / cyc_len;
			cout<< cyc + remain <<endl;
			return 0;
		}
		X[x] = true;
		P.push_back(x);
		sum_p += x;
		x = (ll)x*x % m;
	}
	cout<< sum_p <<endl;
}
