#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) begin(v),end(v)
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
using ll = long long;
using pii = pair<int, int>;
constexpr ll INF = 1ll<<30;
constexpr ll longINF = 1ll<<60;
constexpr ll MOD = 1000000007;
constexpr bool debug = 0;
//---------------------------------//

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	REP(i, N) scanf("%d", &A[i]);
	
	multiset<int> ms;
	REP(i, N) {
		auto it = ms.lower_bound(A[i]);
		if (it == ms.begin()) ms.insert(A[i]);
		else {
			--it;
			ms.erase(it);
			ms.insert(A[i]);
		}
		
	}
	
	cout << ms.size() << endl;
	
	return 0;
}
