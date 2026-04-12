#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
#define ALL(c) (c).begin(), (c).end()
#define REP(i,n) for(ll i=0; i < (n); ++i)
using ll = long long;
using vl = vector<ll>;
int main(){
#ifdef _WIN32
	ifstream cin("sample.in");
	ofstream cout("sample.out");
#endif
	cout << fixed << setprecision(8);
	ll n, a, d, m; cin >> n >> a >> d >> m;
	vl x(m), y(m), z(m);
	REP(i, m) cin >> x[i] >> y[i] >> z[i];

	ll k; cin >> k;
	vl op;
	for (ll i = m - 1; i >= 0; i--){
		if (y[i] > k || k > z[i]) continue;
		if (x[i] == 0){
			k = z[i] - (k - y[i]);
		}
		else if (x[i] == 1){
			op.push_back(1);
		}
		else if (x[i] == 2){
			op.push_back(2);
		}
	}

	reverse(ALL(op));
	REP(i, k-1) a += d;

	REP(i, op.size()){
		if (op[i] == 1){
			a++;
		}
		else{
			a /= 2;
		}
	}

	cout << a << endl;
}