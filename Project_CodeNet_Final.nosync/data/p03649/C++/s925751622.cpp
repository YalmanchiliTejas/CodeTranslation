#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
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

typedef pair <int, int> P;
template<class T> bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
const int  INF = 1 << 30;
const ll INFL = 1LL<<60;
const ll mod = 1000000007;		





int main() {
	int n;
	cin >> n;
	VLL a(n);
	REP(i, n)cin >> a[i];
	
	ll ans = 0;


	while (true) {
		ll res = 0;
		VLL b(n);
		REP(i, n) {
			res += a[i] / n;
			b[i] = a[i] / n;
		}
		if (res == 0)break;
		REP(i, n) {
			a[i] = a[i] - n * b[i] + (res - b[i]);
		}
		ans += res;
	}


	cout << ans << endl;
}