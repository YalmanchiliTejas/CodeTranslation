// failed to generate code

#include <bits/stdc++.h>
using namespace std;
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
template<class T> inline T sqr(T x) {return x*x;}
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(auto i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) sort((c).rbegin(),(c).rend())
#define UNIQUE(c) SORT(c); (c).erase(unique((c).begin(), (c).end()), (c).end());
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
const double INF = 1e7;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
#define CLR(a) memset((a), 0 ,sizeof(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;


int main() {
	LL N;
	cin >> N;
	vector<LL> A(N);
	REP(i, N) {
		cin >> A[i];
	}
/*
	cout << endl;
	REP(i, N) {
		cout << A[i] << " ";
	}
	cout << endl;
*/
	SORT(A);
/*
	cout << endl;
	REP(i, N) {
		cout << A[i] << " ";
	}
	cout << endl;
*/
	deque<LL> C;
	C.push_back(A[0]);   // min value
	LL s = 1, e = N - 1;
	while (1) {
		C.push_front(A[e]);
		e--;
		if (s > e) {
			break;
		}
		LL val = A[e];
		e--;
		if (s > e) {
			if (abs(C[0] - val) >= abs(C[SZ(C) - 1] - val)) {
				C.push_front(val);
			} else {
				C.push_back(val);
			}
			break;
		}		else {
			C.push_back(val);
		}
		C.push_front(A[s]);
		s++;
		if (s > e) {
			break;
		}
		val = A[s];
		s++;
		if (s > e) {
			if (abs(C[0] - val) >= abs(C[SZ(C) - 1] - val)) {
				C.push_front(val);
			} else {
				C.push_back(val);
			}
			break;
		}		else {
			C.push_back(val);
		}
	}
/*
	cout << endl;
	REP(i, SZ(C)) {
		cout << C[i] << " ";
	}
	cout << endl;
	cout << endl;
*/

	LL ans = 0;
	REP(i, SZ(C) - 1) {
		ans += abs(C[i + 1] - C[i]);
	}
	cout << ans << endl;

	return 0;
}
