// E - Sequence Sum
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main(){
	ll n; int x, m; cin>>n>>x>>m;
	int mn = min(n, (ll)m);
	vector<int> P; // pre_sum
	ll sum_p = 0; // sum of pre + cycle
	vector<int> X(m, -1); // for cycle check & pre_len
	for(int i=0; i<mn; ++i){
		if(X[x] > -1){
			int cyc_len = P.size() - X[x];
			ll cyc = (sum_p - P[X[x]]) * ((n - X[x]) / cyc_len);
			ll remain = P[X[x] + (n - X[x]) % cyc_len];
			cout<< cyc + remain <<endl;
			return 0;
		}
		P.push_back(sum_p);
		sum_p += x;
		X[x] = i;
		x = (ll)x*x % m;
	}
	cout<< sum_p <<endl;
}
