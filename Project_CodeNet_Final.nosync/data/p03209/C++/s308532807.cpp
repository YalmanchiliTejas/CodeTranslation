// failed to generate code

#include <bits/stdc++.h>
using namespace std;
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
template<class T> inline T sqr(T x) {return x*x;}
typedef vector<long long> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
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


VI L, P, B;
LL p = 0;


void down_layer(LL n, LL x) {
	//cout << n << "(" << L[n] <<")" << " " << x << endl;
	if (x == L[n]) {
		p += P[n];
	} else if (1 < x && x < (L[n] - 1) / 2) {
		down_layer(n - 1, x - 1);
	} else if ((L[n] - 1) / 2 == x) {
		p += P[n - 1];
	} else if ((L[n] + 1) / 2 == x) {
		p += P[n - 1] + 1;
	} else if ((L[n] + 1) / 2 < x && x < L[n] - 1) {
		p += P[n - 1] + 1;
		down_layer(n - 1, x - ((L[n] + 1) / 2));
	} else if (x == L[n] - 1) {
		p += 2 * (P[n - 1]) + 1;
	} else 	if (x <= 1) {
		return;
	} else {
		//cout << "strange\n";
		return;
	}
}


int main() {
	LL N, X;
	cin >> N >> X;

	L.resize(51);
	P.resize(51);
	B.resize(51);
	L[0] = 1;
	P[0] = 1;
	B[0] = 0;
	FOR(i, 1, 51) {
		P[i] = P[i - 1] * 2 + 1;
		B[i] = B[i - 1] * 2 + 2;
		L[i] = P[i] + B[i];
	}

	down_layer(N, X);
	cout << p << endl;
	

	return 0;
}
