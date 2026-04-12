#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long ll;


#define SZ(x) ((int)(x).size())
#define BIT(n) (1ll<<(n))
#define SORT(c) sort((c).begin(),(c).end())
#define RALL(a) (a).rbegin(), (a).rend()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define MP make_pair
#define CLR(a) memset((a), 0 ,sizeof(a))
#define retrun return
#define INF 1000000010ll
#define MOD 1000000007ll
#define REP(i,a,b) for(int i=(a);i<(b);++i)
#define RREP(i,n)  
#define rep(i,n) for(int i=n-1;i>=0;--i)
#define COUT(str) cout << str << endl


template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }
template<class T> inline T sqr(T x) { return x*x; }

int N;

//------------------------------------------------------------------------------------------------------

int main() {
	cin >> N;

	if (N == 3 or N == 5 or N == 7) {
		COUT("YES");
	}

	else {
		COUT("NO");
	}


	return 0;
}
