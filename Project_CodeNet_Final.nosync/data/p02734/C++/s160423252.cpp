#include <bits/stdc++.h>
using namespace std;

#define mainspring cout<<"mainspring\n";
#define barrel cout<<"barrel\n";
#define escapement cout<<"escapement\n";

#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end() 
#define sz(v) (int)((v).size())
#define fs first
#define sd second
#define tik(i,a,b) for(int i = a; i < b; i++)
#define tok(i,a,b) for(int i = a; i >= b; i--)
#define error(args...) {string _s = #args; replace(_s.begin(), _s.end(), ',',' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it,args);}

typedef long long ll;
typedef unsigned long long ull;

typedef pair < int, int > pi;
typedef pair < pi, int > ppi;

typedef vector < int > vi;
typedef vector < vector < int > > vvi;
typedef vector < pi > vpi;
typedef vector < vpi > vvpi;
typedef vector < ppi > vppi;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void err(istream_iterator<string> it) {cout << endl;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << " ";
    err(++it, args...);
}

const int MOD = 998244353;
#define int ll

int32_t main() {
	int n, s;
	cin >> n >> s;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int dp[n][3010] = {0}; //dp[i][j] = all subsequences which end with a[i] and sum to j, stores the sum of all their (left index + 1)
	vi pref(3010, 0);
	for(int i = 0; i < n; i++) {
		//get dp[i][j]
		//vi temp(3010,0);
		dp[i][a[i]] = i + 1;
		for(int j = a[i] + 1; j < 3010; j++)  {
			dp[i][j] = pref[j - a[i]];
			// temp[j] = pref[j] + dp[i][j];
			// for(int k = 0; k <  i; k++)
			// 	dp[i][j] += dp[k][j - a[i]];
		}
		for(int j = a[i]; j < 3010; j++) {
			pref[j] += dp[i][j];
			pref[j] %= MOD;
		}
		// temp[a[i]] = pref[a[i]] + i + 1;
		// pref = temp;
	}
	ll res = 0;
	for(int i = 0; i < n; i++) {
		//error(dp[i][s]);
		res = (res + 1LL*dp[i][s]*(n - i))%MOD;
	}
	cout << res;
}