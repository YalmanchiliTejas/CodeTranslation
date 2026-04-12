// E - Sequence Sum
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main(){
	ll n; int x, m; cin>>n>>x>>m;
	vector<int> X(m, -1);
	vector<int> P;
	ll sum_p = 0;
	while(X[x] < 0){ // preset
		X[x] = P.size(); // pre length
		P.push_back(sum_p); // pre sum_p
		sum_p += x; // now sum_p
		x = (ll)x*x % m;
	}
	int nxt_len = (n - X[x]) % (P.size() - X[x]);
	ll cyc_times = (n - X[x]) / (P.size() - X[x]);
	ll cyc = (sum_p - P[X[x]]) * cyc_times;
	ll remain = P[X[x] + nxt_len];
	cout<< cyc + remain <<endl;
}
