#ifdef LOCAL111
	#define _GLIBCXX_DEBUG
#else
	#define NDEBUG
#endif
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
const long long INF = 1e18+5;
using namespace std;
template<typename T, typename U> ostream& operator<< (ostream& os, const pair<T,U>& p) { cout << '(' << p.first << ' ' << p.second << ')'; return os; }

#define endl '\n'
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#ifdef LOCAL111
	#define DEBUG(x) cout<<#x<<": "<<(x)<<endl
	template<typename T> void dpite(T a, T b){ for(T ite = a; ite != b; ite++) cout << (ite == a ? "" : " ") << *ite; cout << endl;}
#else
	#define DEBUG(x) true
	template<typename T> void dpite(T a, T b){ return; }
#endif
#define F first
#define S second
#define SNP string::npos
#define WRC(hoge) cout << "Case #" << (hoge)+1 << ": "
template<typename T> void pite(T a, T b){ for(T ite = a; ite != b; ite++) cout << (ite == a ? "" : " ") << *ite; cout << endl;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}

typedef long long int LL;
typedef unsigned long long ULL;
typedef pair<int,int> P;

void ios_init(){
	//cout.setf(ios::fixed);
	//cout.precision(12);
#ifdef LOCAL111
	return;
#endif
	ios::sync_with_stdio(false); cin.tie(0);
}

int main()
{
	ios_init();
	int n;
	while(cin >> n) {
		vector<LL> x(n),y(n);
		REP(i,n) cin >> x[i] >> y[i];
		
		REP(i,n) if(x[i] > y[i]) swap(x[i],y[i]);

		using P = pair<LL,LL>;
		vector<P> xy(n);
		
		LL mi = *min_element(ALL(x));
		LL ma = *max_element(ALL(y));
		
		bool f = false;
		bool f1 = false, f2 = false;
		REP(i,n){
			if(x[i] == mi and y[i] != ma) f1 = true;
			if(y[i] == ma and x[i] != mi) f2 = true;
		}
		f = (f1 and f2);
		DEBUG(f);
		REP(i,n) xy[i] = {x[i],y[i]};

		sort(ALL(x)); sort(ALL(y));
		LL ans = (x.back()-x[0])*(y.back()-y[0]);
		
		sort(ALL(xy));
		if(f){
			multiset<LL> s;
			REP(i,n){
				s.insert(xy[i].F);
			}
			REP(i,n){
				s.erase(s.find(xy[i].F));
				s.insert(xy[i].S);
				chmin(ans,(ma-mi)*-(*s.begin()-*(--s.end())));
			}
		}
		cout << ans << endl;


		// LL mir = xy[0].F;
		// LL mar = INF;
		// LL mib = INF;
		// REP(i,n){
		// 	if(xy[i].F ){

		// 	}
		// }
	}
	return 0;
}
