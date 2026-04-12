#include <bits/stdc++.h>
using namespace std;

#define start_routine() int begtime = clock();
#define end_routine() int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0
#define speed() cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define exit(a, b) return cout << a, b;

#define PB push_back
#define MP make_pair

#define sd(n) scanf("%lld", &n)
#define pdn(n) printf("%lld\n", n);
#define pds(n) printf("%lld ", n);
#define endl '\n'

#define forn(a, b, i) for (int i = a; i < b; i += 1)
#define all(v) v.begin(), v.end() 

using vi = vector<int>;
using vb = vector<bool>;
using pii = pair<int, int>;
using mii = map<int, int>;

#define print(stuff) cout << stuff << endl
#define len(stuff) stuff.size()

#define int long long
#define float long double 

const int upper = 4e5 + 2;
const int M = (int) 1e9 + 7;
const int inf = (int) 1e17;
const double eps =  1e-8;

int pw[100001];
int dp[10001][101][2];

signed main () {
	start_routine();
	speed();
	#ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);	
	// freopen("output.txt", "w", stdout);
	// freopen("errlog.txt", "w", stderr);
	#endif

	string k; 
	int d;
	cin >> k >> d;

	vector<int> n;
	for (auto i: k) {
		n.push_back(i - '0');
	}

	pw[0] = 1; 
	for (int i = 1; i <= 100000; i++) {
		pw[i] = (pw[i - 1] * 10) % d;
	}
	memset(dp, 0LL, sizeof dp);
	int sz = (int) k.size();

	for (int i = 0; i <= n[0]; i += 1) {
		dp[0][i % d][1 - (int) (i == n[0])] += 1;
	}
	for (int j = 1; j < sz; j += 1) {
		for (int newdig = 0; newdig < 10; newdig += 1) {
			for (int rem = 0; rem < d; rem += 1) {
				dp[j][(rem + newdig) % d][1] += ((newdig < n[j]) ? (dp[j - 1][rem][0]) : 0);
				dp[j][(rem + newdig) % d][1] += dp[j - 1][rem][1];
				dp[j][(rem + newdig) % d][0] += ((newdig == n[j]) ? (dp[j - 1][rem][0]) : 0);  

				dp[j][(rem + newdig) % d][1] %= M;
				dp[j][(rem + newdig) % d][0] %= M;
			}
		}
	}

	cout << (dp[sz - 1][0][1] + dp[sz - 1][0][0] - 1 + M) % M;
 	end_routine();	
}