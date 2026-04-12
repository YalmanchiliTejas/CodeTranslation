#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVC vector<vector<char>>
#define fore(i,a) for(auto &i:a)
typedef long long ll;
typedef pair <int, int> P;
template<class T> bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
const int  INF = 2147483647;
const ll INFL = 9223372036854775807;
const ll mod = 1000000007;


int main() {
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	if (k == 0) {
		cout << ll(n) * ll(n) << endl;
		return 0;
	}
	FOR(i, 1, n + 1) {
		ans += (n / i * max(0, i - k)) + max(0, n%i - k+1);
	}
	cout << ans << endl;
}
