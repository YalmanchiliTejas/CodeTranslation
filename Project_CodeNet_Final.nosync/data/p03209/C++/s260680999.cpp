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
#define VVS vector<vector<string>>
#define VVC vector<vector<char>>
#define fore(i,a) for(auto &i:a)
typedef long long ll;
typedef pair <int, int> P;
const int  INF = 2147483647;
const ll INFL = 9223372036854775807;
const ll mod = 1000000007;

using namespace std;


VLL a(52), b(52);
ll c, x;

ll solve(ll n, ll m) {
	if (n == 0) {
		if (m <= 0)return 0;
		else return 1;
	}
	else if (m <= 1 + a[n - 1]) return solve(n - 1, m - 1);
	else return b[n - 1] + 1 + solve(n - 1, m - 2 - a[n - 1]);
}

int main() {
	cin >> c >> x;
	
	a[0] = b[0] = 1;
	REP(i, 51) {
		a[i + 1] = a[i] * 2 + 3;
		b[i + 1] = b[i] * 2 + 1;
	}

	cout << solve(c, x) << endl;

	return 0;
}
