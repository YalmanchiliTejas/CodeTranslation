#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) begin(v),end(v)
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
using ll = long long;
constexpr ll MOD = 1000000007;
//---------------------------------//



int main() {
	string T, P;
	cin >> T >> P;
	
	bool ans = true;
	puts([&] {
		vector<int> v[2];
		REP(times, 2) {
			int pos = 0, idx = 0;
			while (pos < T.size() && idx < P.size()) {
				if (T[pos] == P[idx]) {
					v[times].emplace_back(pos);
					++pos; ++idx;
				}
				else ++pos;
			}
			if (idx < P.size()) return false;
			reverse(ALL(T));
			reverse(ALL(P));
		}
		
		for (int &u : v[1]) u = T.size() - 1 - u;
		reverse(ALL(v[1]));
		return v[0] == v[1];
		
		
	}() ? "yes": "no");
	
	return 0;
}

