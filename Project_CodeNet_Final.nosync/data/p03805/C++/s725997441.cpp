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
#define PI (acos(-1))
#define EPS (1e-10)
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
using Complex = std::complex<double>;
using namespace std;


int N, M;
bool ab[30][30];


bool judge(VI& v){
	if(v[0] != 0) return false;
	rep(i, 0, SIZE(v)-1)
		if(!ab[v[i]][v[i+1]]) return false;
	return true;
}


int solve(){
	int ans = 0;
	VI v(N, 0);
	iota(ALL(v), 0);
	do {
		if(judge(v)) ans++;
	} while(next_permutation(ALL(v)));
	return ans;
}


signed main(){
	cin >> N >> M;
	rep(i, 0, M){
		int a, b;
		cin >> a >> b;
		a--, b--;
		ab[a][b] = true;
		ab[b][a] = true;
	}

	cout << solve() << endl;

	return 0;
}