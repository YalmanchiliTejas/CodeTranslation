#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define dprint(Exp,...) if(Exp){fprintf(stderr, __VA_ARGS__);}
#define printe(...) fprintf(stderr, __VA_ARGS__);
#define PrtExp(_Exp)  cerr<< #_Exp <<" = "<< (_Exp)
#define PrtExpN(_Exp)  cerr<< #_Exp <<" = "<< (_Exp) <<"\n"

#define SINT(n) scanf("%d",&n)
#define SINT2(n,m) scanf("%d %d",&n,&m)
#define SINT3(n,m,o) scanf("%d %d %d",&n,&m,&o)
#define SINT4(n,m,o,p) scanf("%d %d %d %d",&n,&m,&o,&p)
#define SINT5(n,m,o,p,q) scanf("%d %d %d %d %d",&n,&m,&o,&p,&q)
#define SLL(n) scanf("%lld",&n)
#define SLL2(n,m) scanf("%lld %lld",&n,&m)
#define SLL3(n,m,o) scanf("%lld %lld %lld",&n,&m,&o)
#define SST(s) scanf("%s",s)
#define SCH(c) scanf("%c",&c)

#define GC() getchar()

#define PINT(n) printf("%d",(int)(n))
#define PINT2(n,m) printf("%d %d",(int)(n),(int)(m))
#define PINT3(n,m,l) printf("%d %d %d",(int)(n),(int)(m),(int)(l))
#define PLL(n) printf("%lld",(long long)(n))
#define PST(s) printf("%s",(s))
#define PCH(s) printf("%c",(s))

#define PINTN(n) printf("%d\n",(int)(n))
#define PINT2N(n,m) printf("%d %d\n",(int)(n),(int)(m))
#define PINT3N(n,m,l) printf("%d %d %d\n",(int)(n),(int)(m),(int)(l))
#define PLLN(n) printf("%lld\n",(long long)(n))
#define PSTN(s) printf("%s\n",(s))
#define PCHN(s) printf("%c\n",(s))

#define PSP() printf(" ")
#define PN() printf("\n")

#define PC(c) putchar(c)
#define CSP (' ')
#define SN ("\n")

#define rep(i,a) for(int i=0;i<a;i++)
#define reP(i,a) for(int i=0;i<=a;i++)
#define Rep(i,a) for(int i=a-1;i>=0;i--)
#define ReP(i,a) for(int i=a;i>=0;i--)

#define rEp(i,a) for(i=0;i<a;i++)
#define rEP(i,a) for(i=0;i<=a;i++)
#define REp(i,a) for(i=a-1;i>=0;i--)
#define REP(i,a) for(i=a;i>=0;i--)

#define repft(i,a,b) for(int i=a;i<b;i++)
#define repfT(i,a,b) for(int i=a;i<=b;i++)
#define Repft(i,a,b) for(int i=a-1;i>=b;i--)
#define RepfT(i,a,b) for(int i=a;i>=b;i--)

#define foreach(a,it) for(auto it = a.begin(); it != a.end(); ++it)

#define FILL(a,v) fill(begin(a),end(a), v)
#define FILL0(a) memset(a,0,sizeof(a))
#define FILL1(a) memset(a,-1,sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll>   Pll;


const int INF = 0x2aaaaaaa; // 715,827,882
const ll INFLL = 0x1f1f1f1f1f1f1f1fLL;//2,242,545,357,980,376,863

template <class A, class B> inline ostream& operator<<(ostream& st, const pair<A, B>& P) { return st << "(" << P.first << "," << P.second << ")"; };
template <class A, class B> inline pair<A, B> operator+(const pair<A, B>& P, const pair<A, B>& Q) { return pair<A, B>(P.first + Q.first, P.second + Q.second); };
template <class A, class B> inline pair<A, B> operator-(const pair<A, B>& P, const pair<A, B>& Q) { return pair<A, B>(P.first - Q.first, P.second - Q.second); };


#define fs  first
#define sc  second


struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) {}
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};


typedef pair<ll, Pi> Piii;
typedef pair<Pi, int> Piii2;

priority_queue<Piii> Q;

Piii2 xy[100000];
Piii2 yx[100000];


int main() {
	
	int N;

	cin >> N;

	rep(i, N) {
		int x, y;
		cin >> x >> y;
		xy[i] = { { x, y },i };
		yx[i] = { { y, x },i };
	}
	sort(xy, xy + N);
	sort(yx, yx + N);

	rep(i, N-1) {
		ll d = min(abs(xy[i].fs.fs - xy[i+1].fs.fs), abs(xy[i].fs.sc - xy[i+1].fs.sc));
		Q.push({ -d,{ xy[i].sc, xy[i+1].sc } });
	}

	rep(i, N - 1) {
		ll d = min(abs(yx[i].fs.fs - yx[i + 1].fs.fs), abs(yx[i].fs.sc - yx[i + 1].fs.sc));
		Q.push({ -d,{ yx[i].sc, yx[i + 1].sc } });
	}


	int cnt = 1;
	UnionFind U(N);
	ll ret = 0;
	for (;;) {
		auto t = Q.top(); Q.pop();

		if (U.unionSet(t.sc.fs, t.sc.sc)) {
			cnt++;
			ret += -t.fs;
			if (cnt == N) break;
		}
	}
	cout << ret << endl;


}