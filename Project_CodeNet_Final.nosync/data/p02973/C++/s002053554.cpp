#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1ll<<30;
const ll longINF = 1ll<<60;
const ll MOD = 1000000007;
const double EPS = 1e-9;
const bool debug = 0;
//---------------------------------//

int N;
int A[112345];

int main() {
	cin >> N;
	REP(i, N) scanf("%d", A + i);
	
	multiset<int> ss;
	ss.insert(A[0]);
	FOR(i, 1, N) {
		auto it = ss.lower_bound(A[i]);
		if (it != ss.begin()) {
			--it;
			ss.erase(it);
		}
		ss.insert(A[i]);
	}
	
	cout << ss.size() << endl;
	
	return 0;
}
