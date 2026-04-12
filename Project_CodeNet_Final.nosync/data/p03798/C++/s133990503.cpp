#include <bits/stdc++.h>
#define rep(i, a, n) for(int (i) = (int)(a);(i) < (int)(n);++(i))
#define repe(i, a, n) for(int (i) = (int)(a);(i) <= (int)(n);++(i))
#define repif(i, a, x) for(int (i) = (int)(a);(x);++(i))
#define repr(i, a, n) for(int (i) = ((int)(a)-1);(i) >= (int)(n);--(i))
#define reper(i, a, n) for(int (i) = (int)(a);(i) >= (int)(n);--(i))
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define RNG(x, a, n) &((x)[a]), &((x)[n])
#define ADD(a, b) ((((a+MOD)%MOD)+((b+MOD)%MOD))%MOD)
#define MUL(a, b) ((((a)%MOD)*((b)%MOD))%MOD)
#define CEIL(x) ((int)ceil(((double)x)))
#define POW(x, y) ((int)pow(x, y))
#define UNIQUE(x) (x).erase(unique(ALL((x))), (x).end())
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define yes cout << "yes" << endl;
#define no cout << "no" << endl;
#define fcout cout << fixed << setprecision(10)
#define pb push_back
#define pf push_front
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define EPS (1e-20)
#define INF INT_MAX
#define INFLL LLONG_MAX
#define MOD 1000000007
using llint = long long;
using VI = std::vector<int>;
using PII = std::pair<int, int>;
using SI = std::set<int>;
using MII = std::map<int, int>;
using TIII = std::tuple<int, int, int>;
using MCI = std::map<char, int>;
using VPII = std::vector<PII>;
using namespace std;


int N;
string s;
char a[2] = { 'S', 'W' };


int state(char x, char y){
	if((x == 'S' && y == 'o') || (x == 'W' && y == 'x')) return 0;
	return 1;
}


string judge(char x, char y){
	string res = { x, y };
	rep(i, 1, N-1)
		if(state(res[i], s[i]) == 0) res.pb(res[i-1]);
		else res.pb(a[res[i-1]=='S']);
	if(state(res[0], s[0]) == 0 && res[N-1] != res[1]) return "!";
	else if(state(res[0], s[0]) == 1 && res[N-1] == res[1]) return "!";
	rep(i, 1, N-1)
		if(state(res[i], s[i]) == 0 && res[i-1] != res[i+1]) return "!";
		else if(state(res[i], s[i]) == 1 && res[i-1] == res[i+1]) return "!";
	if(state(res[N-1], s[N-1]) == 0 && res[N-2] != res[0]) return "!";
	else if(state(res[N-1], s[N-1]) == 1 && res[N-2] == res[0]) return "!";
	return res;
}


string solve(){
	char x[2] = { 'S', 'W' };
	rep(i, 0, 2)
		rep(j, 0, 2)
			if(judge(x[i], x[j]) != "!") return judge(x[i], x[j]);
	return "-1";
}


signed main(){
	cin >> N;
	cin >> s;

	cout << solve() << endl;

	return 0;
}