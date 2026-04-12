#ifdef LOCAL111
	#define _GLIBCXX_DEBUG
#else
	#define NDEBUG
#endif
#include <bits/stdc++.h>
const int INF = 1e9;
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
typedef pair<LL,LL> LP;

void ios_init(){
	//cout.setf(ios::fixed);
	//cout.precision(12);
#ifdef LOCAL111
	return;
#endif
	ios::sync_with_stdio(false); cin.tie(0);	
}

const int dx[] = {1,0};
const int dy[] = {0,1};

int main()
{
	ios_init();
	int h,w;
	while(cin >> h >> w) {
		vector<string> a(h);
		REP(i,h) cin >> a[i];
		int x = 0, y = 0;
		auto check = [&](int x, int y){
			return 0 <= x and x < h and 0 <= y and y < w;
		};
		bool f = true;
		while(f){
			DEBUG(x); DEBUG(y);
			a[x][y] = '.';
			f = false;
			REP(k,2){
				if(check(x+dx[k],y+dy[k]) and a[x+dx[k]][y+dy[k]] == '#'){
					f = true;
					x += dx[k];
					y += dy[k];
					break;
				}
			}
		}
		REP(i,h) DEBUG(a[i]);
		string ans = "Possible";
		if(!(x == h-1 and y == w-1)){
			ans = "Impossible";
		}
		REP(i,h) REP(j,w) if(a[i][j] != '.') ans = "Impossible";
		cout << ans << endl;
	}
	return 0;
}
