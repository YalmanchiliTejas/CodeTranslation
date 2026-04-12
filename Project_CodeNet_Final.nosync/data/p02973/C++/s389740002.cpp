/*
ID: thanhvq1
LANG: C++14
PROB: namenum
*/

#pragma GCC optimize ("O2")
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

// defines
#define int long long
typedef long long ll;
#define double long double
#define vec vector
#define vi vector<int>
#define vvi vector<vector<int>>
#define FZ(n) memset((n),0,sizeof())
#define FMO(n) memset((n),-1,sizeof(n))
#define unset unordered_set
#define ii pair<int, int>
#define vii vector<ii>
#define F first;
#define S second
#define mp make_pair
#define PB push_back
#define ALL(x) begin(x),end(x)
#define SZ(x) ((int)(x).size())
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORE(i, a, b) for(int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)
#define bitcount(n) __builtin_popcountll(n)
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define max3(a, b, c) max(a, b) > max(b, c) ? max(a, b) : max(b, c)
#define min3(a, b, c) min(a, b) < min(b, c) ? min(a, b) : min(b, c)

//permanent constants
const long long ZERO = 0LL;
const long long INF64 = 1e18;
const int INF32 = 1e9;
const int MOD = 998244353; //1e9 + 7;  const ll MOD2 = (ll)MOD * (ll)MOD;
const double PI = 2.0*acos(0.0); //acos(-1.0L);
const double EPS = static_cast<double>(1e-10);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int dx[4] = {0, 1, 0, -1}; const int dy[4] = {1, 0, -1, 0};
//const ll INF = (ll)(1e18 + 239);
const int BIG = (int)(1e9 + 239);

//random
mt19937 rnd(239); //(chrono::high_resolution_clock::now().time_since_epoch().count());

void FILEIO() {  freopen("in.txt", "r", stdin);  freopen("out.txt", "w", stdout); }
//void FILEIO() {  freopen("namenum.in", "r", stdin);  freopen("namenum.out", "w", stdout); }
void input() {   }

/* Finds longest NON-strictly increasing subsequence. O(n log k) algorithm. */
vi findLIS(vector<int> &a) {
	vector<int> p(a.size()), b;
	int u, v;
	if (a.empty()) return b;
	b.push_back(0);
	for (size_t i = 1; i < a.size(); i++) {
         // If next element a[i] is greater than last element of current longest
		// subsequence a[b.back()], just push it at back of "b" and continue
		if (a[b.back()] <= a[i]) {p[i] = b.back(); b.push_back(i); continue;}
       // Binary search to find the smallest element referenced by b which is just bigger than a[i]
       // Note : Binary search is performed on b (and not a).
       // Size of b is always <=k and hence contributes O(log k) to complexity.
		for (u = 0, v = b.size()-1; u < v;) {
			int c = (u + v) / 2;
			if (a[b[c]] <= a[i]) u=c+1; else v=c;
		}
        // Update b if new value is smaller then previously referenced value
		if (a[i] <= a[b[u]]) {
			if (u > 0) p[i] = b[u-1];
			b[u] = i;
		}
	}
	for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
	return b;
}

//signed main() {
//	FILEIO();
//	int a[] = { 1, 9, 3, 1, 8, 1, 11, 1, 4, 5, 6, 4, 19, 7, 1, 7 };
//	vector<int> seq(a, a+sizeof(a)/sizeof(a[0])); // seq : Input Vector
//	vector<int> lis;                              // lis : Vector containing indexes of longest subsequence
//	lis = findLIS(seq);
//	for (size_t i = 0; i < lis.size(); i++) cout << seq[lis[i]] << ", ";
//	cout << "\n";
//	return 0;
//}

void solve() {
	int n; cin >> n;
	vi a(n); FOR(i, 0, n) {cin >> a[i]; a[i]=-a[i];}
	cout << SZ(findLIS(a)) << endl;
}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie();
//  FILEIO();
//auto beginProgram = chrono::steady_clock::now();

//  test();

//  int test = 0;
//  string s; getline(cin, s); int t = stoi(s);
//  while(t--)
  {
//	  cout << "Case " << ++test << ": ";
	  solve();
  }

  //auto endProgram = chrono::steady_clock::now();

  return 0;
}
