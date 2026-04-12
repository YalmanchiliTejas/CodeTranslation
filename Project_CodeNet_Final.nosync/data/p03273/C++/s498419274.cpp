#include<bits/stdc++.h>
using namespace std;
#define ALL(obj) (obj).begin(), (obj).end()
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(int i = (a); i >= (b); i--)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define RREP(i, n) for(int i = n; i >= n; i--)

#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))

#define endl "\n"
#define pb push_back
#define rtn return
#define elif else if

#define MOD 1000000007
 
const int dx[]={1,0,-1,0}, dy[]={0,-1,0,1};

typedef long long ll;
typedef unsigned long long ull;

template <typename T>
inline T GCD(T a,T b){T c;while(b!=0){c=a%b;a=b;b=c;}return a;}
template <typename T>
inline T LCM(T a,T b){T c=GCD(a,b);a/=c;return a*b;}
template <typename T>
inline T nCr(T a,T b){T i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
template <typename T>
inline T nHr(T a,T b){return nCr(a+b-1,b);}
template <typename T>
inline T POW(T a,T b){int i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}

signed main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int h, w;
	char a[100][100];
	cin >> h >> w;
	REP(i, h){
		REP(j, w) cin >> a[i][j];
	}

	vector<int> xh;
	vector<int> xw;

	REP(i, h){
		bool y = true;
		REP(j, w){
			if(a[i][j] != '.') y = false;
		}
		if(y) xh.pb(i);
	}
	REP(j, w){
		bool y = true;
		REP(i, h){
			if(a[i][j] != '.') y = false;
		}
		if(y) xw.pb(j);
	}

	REP(i, h){
		REP(p, xh.size()){
			if(i == xh[p]){
				goto failh;
			}
		}
		REP(j, w){
			REP(q, xw.size()){
				if(j == xw[q]) goto failw;
			}
			cout << a[i][j];
			failw:
			;
		}
		cout << endl;
		failh:
		;
	}
	rtn 0;
}