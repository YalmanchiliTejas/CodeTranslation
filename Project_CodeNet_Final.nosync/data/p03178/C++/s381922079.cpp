#include <bits/stdc++.h>
using namespace std;

#define int ll

#define pb push_back
#define all(v) (v).begin(), (v).end() 
#define sz(v) (int)((v).size())
#define fs first
#define sd second

typedef long long ll;

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

vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}

void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}

#ifdef LOCAL
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

double get_time() {
	return 1.0 * clock() / CLOCKS_PER_SEC;
}

const int MAXN = 1E5 + 10, MAXD = 111, MOD = 1E9 + 7;
string k;
int d, dp[MAXN][MAXD][2];
char c[MAXN];

int solve(int pos, int need, int flag) {
	if(pos == sz(k))
		return need == 0;
	if(dp[pos][need][flag] > -1)
		return dp[pos][need][flag];
	int dig = k[pos] - '0';
	int ret = 0;
	for(int i = 0; i <= 9; i++) {
		if(!flag && i > dig)
			break;
		c[pos] = char('0' + i);
		ret = (ret + solve(pos + 1, (need - i + d) % d, (flag | i < dig))) % MOD;
	}
	return dp[pos][need][flag] = ret;
}	

int32_t main() {
	memset(dp, -1 , sizeof(dp));
	cin >> k >> d;
	cout << (solve(0, d, 0) - 1 + MOD) % MOD << '\n';
}
