#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1e9+100;
const ll INFL = 1e18+100;
const ll MOD = 1e9+7;
const bool debug = 0;
//-----------------------------------------------//

int main() {
	int X, Y, Z;
	cin >> X >> Y >> Z;
	cout << (X - Z) / (Y + Z) << endl;
	return 0;
}