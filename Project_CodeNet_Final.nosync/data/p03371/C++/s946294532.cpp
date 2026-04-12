#include <bits/stdc++.h> 
#define FOR(i,a,b) for(int i=(a);i<=(b);++i) 
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i) 
#define REP(i,n) for(int i=0;i<(n);++i)
#define RREP(i,n) for(int i=(n);i>0;--i)
#define CI cin>> 
#define CO cout<<
#define EN <<endl 
#define all(x) (x).begin(),(x).end() 
#define asn ans
using namespace std;
template <typename T> istream& operator >> (istream& is, vector<T>& vec) { for (T& x : vec) is >> x; 	return is; }
using ll = long long;

int main() {
	int a, b, c, x, y; CI a >> b >> c >> x >> y;
	int zero = 0;
	vector<ll> ans;

	REP(i, 100001) {
		ll tmp = (2 * c*i) + (max(zero, x - i)*a) + (max(zero, y - i)*b);
		ans.push_back(tmp);
	}

	sort(all(ans));
	CO ans[0] EN;

	return 0;
}