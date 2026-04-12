//------------------------------------------
//include
//------------------------------------------
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

//------------------------------------------
//typedef
//------------------------------------------
typedef long long LL;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef vector<VB> VVB;
typedef vector<VS> VVS;
typedef vector<VLL> VVLL;
typedef vector<VVI> VVVI;
typedef vector<VVLL> VVVLL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<int, string> PIS;
typedef pair<string, int> PSI;
typedef pair<string, string> PSS;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<VPII> VVPII;
typedef vector<VPLL> VVPLL;
typedef vector<VS> VVS;

//------------------------------------------
//comparison
//------------------------------------------
#define ALL(a) (a).begin(), (a).end()
#define CHMIN(a, b) a = min((a), (b))
#define CHMAX(a, b) a = max((a), (b))
#define C_ABS(a, b) ((a)<(b) ? (b)-(a) : (a)-(b))

//------------------------------------------
//container util
//------------------------------------------
#define ALL(a)  (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define EACH(i, arr) for (typeof((arr).begin()) i = (arr).begin(); i != (arr).end(); ++i)
#define EXIST(str, e) ((str).find(e) != (str).end())
#define COUNT(arr, v) count((arr).begin(), (arr).end(), v)
#define SEARCH(v, w) search((v).begin(), (v).end(), (w).begin(), (w).end())
#define B_SEARCH(arr, v) binary_search((arr).begin(), (arr).end(), v)
#define SORT(c) sort((c).begin(), (c).end())
#define RSORT(c) sort((c).rbegin(), (c).rend())
#define REVERSE(c) reverse((c).begin(), (c).end())
#define ROTATE_LEFT(arr, c) rotate((arr).begin(), (arr).begin() + (c), (arr).end())
#define ROTATE_RIGHT(arr, c) rotate((arr).rbegin(), (arr).rbegin() + (c), (arr).rend())
#define SUMI(arr) accumulate((arr).begin(), (arr).end(), 0)
#define SUMD(arr) accumulate((arr).begin(), (arr).end(), 0.)
#define SUMLL(arr) accumulate((arr).begin(), (arr).end(), 0LL)
#define SUMS(arr) accumulate((arr).begin(), (arr).end(), string())
#define UB(arr, n) upper_bound((arr).begin(), (arr).end(), n)
#define LB(arr, n) lower_bound((arr).begin(), (arr).end(), n)
#define OF_ALL(arr, func) all_of((arr).begin(), (arr).end(), (func))
#define OF_NONE(arr, func) none_of((arr).begin(), (arr).end(), (func))
#define OF_ANY(arr, func) any_of((arr).begin(), (arr).end(), (func))
#define PB push_back
#define MP make_pair

//------------------------------------------
//input output
//------------------------------------------
#define GL(s) getline(cin, (s))
#define INIT() std::ios::sync_with_stdio(false); std::cin.tie(0);
#define OUT(d) std::cout << (d)
#define OUT_L(d) std::cout << (d) << endl
#define FOUT(n, data) std::cout << std::fixed << std::setprecision(n) << (data)
#define FOUT_L(n, data) std::cout << std::fixed << std::setprecision(n) << (data) << "\n"
#define EL() printf("\n")
#define SHOW_VECTOR(v) { std::cerr << #v << "\t:"; for (const auto& xxx : v) { std::cerr << xxx << " "; }std::cerr << "\n"; }
#define SHOW_MAP(v) { std::cerr << #v << endl; for (const auto& xxx : v) { std::cerr << xxx.first << " " << xxx.second << "\n"; } }
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define YES() printf("YES\n")
#define NO() printf("NO\n")

//------------------------------------------
//repetition
//------------------------------------------
#define FOR(i, a, b) for (int i = (a); i<(b); ++i)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define REP(i, n)  FOR(i, 0, n)
#define RREP(i, n) for (int i = n - 1; i >= 0; i--)
#define FORLL(i, a, b) for (LL i = LL(a); i<LL(b); ++i)
#define RFORLL(i, a, b) for (LL i = LL(b) - 1; i >= LL(a); --i)
#define REPLL(i, n) for (LL i = 0; i<LL(n); ++i)
#define RREPLL(i, n) for (LL i = LL(n) - 1; i >= 0; --i)
#define FOREACH(x, arr) for (auto &(x) : (arr))
#define FORITER(x, arr) for (auto (x) = (arr).begin(); (x) != (arr).end(); ++(x))

//**************************************
//最大公約数
//**************************************
template<class T>
inline T GCD(const T x, const T y) {
	if (x < 0)return GCD(-x, y);
	if (y < 0)return GCD(x, -y);
	return (!y) ? x : GCD(y, x % y);
}

//**************************************
//nの約数
//**************************************
template<typename T>
vector<T> DIVISOR(T n) {
	vector<T> v;
	for (LL i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			v.push_back(i);
			if (i != n / i) {
				v.push_back(n / i);
			}
		}
	}
	sort(v.begin(), v.end());
	return v;
}


//------------------------------------------
// global
//------------------------------------------
//int A = 0;
LL A = 0;
//int B = 0;
LL B = 0;
LL C = 0;
LL D = 0;
LL E = 0;
LL N = 0;
LL M = 0;
LL K = 0;
VLL H;
LL W = 0;
LL Q = 0;
string S = "";
VPLL Pair;
LL i, j, k = 0;
LL ans, ans1, ans2 = 0;

VLL Array;
VC t;

/*
std::string str[3];
int h[100] = {0};
int h_size = 0;
int MinCount = 0;
LL i,j,k = 0;
LL ans1,ans2 = 0;
VLL A;
LL K;
LL K_pow = 0;
LL K_num = 1;
LL tmp = 0;
*/



//------------------------------------------
// read
//------------------------------------------
void read(void) {
	cin >> N;
	H.resize(N);

	REP(i, N) {
		cin >> H[i];
	}

}

int main()
{
	LL sum = 0;
	LL tmp = 0;

	// 初期化
	INIT();

	// 読込み
	read();

	REP(i, N) {
		if (tmp <= H[i]){
			tmp = H[i];
			sum++;
		}	
	}

	printf("%lld\n", sum);

	return 0;
}