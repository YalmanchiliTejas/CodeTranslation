// E - Sequence Sum
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
vector<ll> divmod(ll p,ll m){return {p/m, p%m};}

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
	vector<ll> qr = divmod(n - X[x], P.size() - X[x]);
	ll cyc = (sum_p - P[X[x]]) * qr[0];
	ll remain = P[X[x] + qr[1]];
	cout<< cyc + remain <<endl;
}
