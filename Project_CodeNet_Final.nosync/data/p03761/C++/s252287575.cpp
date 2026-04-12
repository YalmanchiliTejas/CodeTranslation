#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <utility>
#include <numeric>
#include <string>
#include <set>
#include <map>
#include <tuple>
#include <queue>
#include <stack>
#include <deque>
#define rep(i, a, n) for(int (i) = (int)(a);(i) < (int)(n);++(i))
#define repe(i, a, n) for(int (i) = (int)(a);(i) <= (int)(n);++(i))
#define repif(i, a, x) for(int (i) = (int)(a);(x);++(i))
#define repr(i, a, n) for(int (i) = (int)(a);(i) > (int)(n);--(i))
#define reper(i, a, n) for(int (i) = (int)(a);(i) >= (int)(n);--(i))
#define SIZE(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define RNG(x, n) &((x)[0]), &((x)[n])
#define BRK(x) { (x); break; }
#define ADD(a, b) ((((a)%MOD)+((b)%MOD))%MOD)
#define MUL(a, b) ((((a)%MOD)*((b)%MOD))%MOD)
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define yes cout << "yes" << endl;
#define no cout << "no" << endl;
#define fcout cout << fixed << setprecision(10)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define EPS (1e-20)
#define INF 2147483647
#define MOD 1000000007
using llint = long long;
using VI = std::vector<int>;
using PII = std::pair<int, int>;
using SI = std::set<int>;
using MII = std::map<int, int>;
using TIII = std::tuple<int, int, int>;
using VLL = std::vector<llint>;
using MCI = std::map<char, int>;
using namespace std;


int n;
MCI cnt[60];


string solve(){
	MCI ansC = cnt[0];
	rep(i, 1, n)
		for(PII p : cnt[i])
			ansC[p.fi] = min(ansC[p.fi], p.se);
	string ans;
	for(PII p : ansC)
		rep(i, 0, p.se) ans.pb(p.fi);
	return ans;
}


signed main(){
	cin >> n;
	rep(i, 0, n){
		string S;
		cin >> S;
		rep(j, 0, 26) cnt[i]['a'+j] = 0;
		for(char c : S) cnt[i][c]++;
	}

	cout << solve() << endl;

	return 0;
}