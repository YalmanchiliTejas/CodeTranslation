#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;++i)
#define REPR(i, n) for(int i = n;i >= 0;--i)
#define FOR(i, m, n) for(int i = m;i < n;++i)
#define FORR(i, m, n) for(int i = m;i >= n;--i)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define FI first
#define SE second
#define PB(a) push_back(a)
#define DEBUG(x) cerr << __LINE__ << ":" << #x << ": " << x << "\n";
#define SZ(x) ((int)(x).size())
#define SO(x) sizeof((x)) / sizeof((x)[0])
//#define int long long
using namespace std;
using lint = long long;
struct Fast{Fast(){cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);};} fast;
const int INF = INT_MAX;
const lint LINF = LLONG_MAX;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
inline int in() {int x; cin >> x; return x;}
inline lint IN() {lint x; cin >> x; return x;}
inline void co(int a[], int n) {REP(i, n) cout << a[i] << " "; cout << "\n";}
//if (IO > 1e5){lint a;	scanf(%lld, &a);	printf("%lld\n", a);}

signed main(){
	int h = in();	int w = in();
	int a[h][w];	char temp;
	bool ch = true;	bool cw[h];
	REP(i,h) cw[i] = true;
	REP(i,h){
		REP(j,w){
			cin >> temp;
			if (temp == '.'){
				a[i][j] = 1;
			}else{
				a[i][j] = 2;
				cw[i] = false;
			}
		}
		if (cw[i] == true){
			REP(k,w) a[i][k] = 0;
		}
	}
	
	REP(j,w){
		REP(i,h){
			if (a[i][j] == 2) ch = false;
		}
		if (ch == true){
			REP(k,h) a[k][j] = 0;
		}else{
			ch = true;
		}
	}
	
	/*
	REP(i,h){
		REP(j,w){
			cout << a[i][j];
		}
		cout << "\n";
	}
	*/
	
	REP(i,h){
		REP(j,w){
			if (a[i][j] == 1){
				cout << '.';
			}else if (a[i][j] == 2){
				cout << '#';
			}
		}
		//cout << cw[i];
		if (cw[i] == false) cout << "\n";
	}
return 0;
}
