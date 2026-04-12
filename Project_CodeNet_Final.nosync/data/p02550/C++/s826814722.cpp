// E - Sequence Sum
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rp(i,s,e) for(int i=(int)(s);i<(int)(e);++i)

int main(){
	ll n; int x, m; cin>>n>>x>>m;
	int mn = min(n, (ll)m);
	vector<int> P; // value of pre & cycle
	ll sum_p = 0; // sum of pre + cycle
	vector<bool> X(m, false); // for cycle check
	while(mn--){
		if(X[x]){
			int pre_len = find(P.begin(), P.end(), x) - P.begin();
			int cyc_len = P.size() - pre_len;
			int nxt_len = (n - pre_len) % cyc_len;
			ll pre = 0; rp(i, 0, pre_len) pre += P[i];
			ll nxt = 0; rp(i, pre_len, pre_len + nxt_len) nxt += P[i];
			ll cyc = (sum_p - pre) * ((n - pre_len) / cyc_len);
			cout<< pre + cyc + nxt <<endl;
			return 0;
		}
		X[x] = true;
		P.push_back(x);
		sum_p += x;
		x = (ll)x*x % m;
	}
	cout<< sum_p <<endl;
}
