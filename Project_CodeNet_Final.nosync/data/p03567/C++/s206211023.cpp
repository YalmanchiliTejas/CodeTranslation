#include <iostream>
#include <fstream>
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string> 
#include <vector>
#include <bitset>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define REP(i,n) for(int i = 0; i < int(n); i++)
#define REREP(i,n) for(int i = int(n - 1); i >= 0; i--)
#define FOR(i, m, n) for(int i = int(m);i < int(n);i++)
#define REFOR(i, m, n) for(int i = int(n - 1);i >= int(m);i--)
#define ALL(obj) (obj).begin(),(obj).end()

#define VI vector<int>
#define VVI vector<vector<int>>
#define VVVI vector<vector<vector<int>>>
#define VD vector<double>
#define VVD vector<vector<double>>
#define VVVD vector<vector<vector<double>>>
#define VL vector<ll>
#define VVL vector<vector<ll>>
#define VVVL vector<vector<vector<ll>>>
#define VB vector<bool>
#define VVB vector<vector<bool>>
#define VVVB vector<vector<vector<bool>>>
#define VS vector<string>
#define VVS vector<vector<string>>
#define VVVS vector<vector<vector<string>>>

#define PII pair<int,int>
#define PDD pair<double,double>
#define PLL pair<ll,ll>
#define VPII vector<pair<int,int>>
#define VVPII vector<vector<pair<int,int>>>
#define VVVPII vector<vector<vector<pair<int,int>>>>
#define VPLL vector<pair<ll,ll>>
#define VVPLL vector<vector<pair<ll,ll>>>
#define VVVPLL vector<vector<vector<pair<ll,ll>>>>

const ll MOD = (ll)1e9 + 7; // 998244353
const ll HINF = (ll)1e18;
const ll LINF = (ll)1e9;
const long double PI = 3.1415926535897932384626433;


void YN(bool flag) {
	cout << ((flag) ? "YES" : "NO") << endl;
}

void Yn(bool flag) {
	cout << ((flag) ? "Yes" : "No") << endl;
}

void yn(bool flag) {
	cout << ((flag) ? "yes" : "no") << endl;
}

int main() {
	string s; cin >> s;
	bool flg = false;
	REP(i, s.size()-1) if (s[i] == 'A' && s[i + 1] == 'C') flg = true;
	Yn(flg);

	return 0;
}
