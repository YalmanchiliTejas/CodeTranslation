#ifdef LOCAL111
	#define _GLIBCXX_DEBUG
#else
	#define NDEBUG
#endif
#define _USE_MATH_DEFINES
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
typedef pair<LL,LL> P;

void ios_init(){
	//cout.setf(ios::fixed);
	//cout.precision(12);
#ifdef LOCAL111
	return;
#endif
	ios::sync_with_stdio(false); cin.tie(0);	
}

//library

class UFTree {
//private:
public:
	vector<int> par;
	vector<int> rank;
	vector<int> num;

//public:
	UFTree(int n)
	{
		par = vector<int>(n);
		rank = vector<int>(n);
		num = vector<int>(n);
		for(int i = 0; i < n; i++){
			par[i] = i;
			rank[i] = 0;
			num[i] = 1;
		}
	}

	int find(int x)
	{
		if(par[x] == x){
			return x;
		}else{
			return par[x] = find(par[x]);
		}
	}

	void unite(int x, int y)
	{
		x = find(x);
		y = find(y);
		if(x == y) return;
		if(rank[x] < rank[y]){
			par[x] = y;
			num[y] += num[x];
		}else{
			par[y] = x;
			num[x] += num[y];
			if(rank[x] == rank[y])	rank[x]++;
		}
	}

	int count(int x)
	{
		return num[find(x)];
	}

	bool same(int x, int y)
	{
		return find(x) == find(y);
	}
};
//library

int main()
{
	ios_init();
	int n;
	while(cin >> n) {
		vector<P> xy(n);
		REP(i,n){
			cin >> xy[i].F >> xy[i].S;
		}
		UFTree uf(n);
		vector<P> xa(n), ya(n);
		REP(i,n){
			xa[i] = {xy[i].F,i};
			ya[i] = {xy[i].S,i};
		}
		sort(ALL(xa)); sort(ALL(ya));
		// xa.erase(unique(ALL(xa)), xa.end());
		// ya.erase(unique(ALL(ya)), ya.end());
		using PP = pair<LL,P>;
		vector<PP> v;
		REP(i,SZ(xa)-1){
			v.emplace_back(xa[i+1].F-xa[i].F,P({xa[i].S, xa[i+1].S}));
		}
		REP(i,SZ(ya)-1){
			v.emplace_back(ya[i+1].F-ya[i].F,P{ya[i].S, ya[i+1].S});
		}
		sort(ALL(v));
		LL ans = 0;
		REP(i,SZ(v)){
			P p;
			LL c;
			tie(c, p) = v[i];
			if(!uf.same(p.F, p.S)){
				uf.unite(p.F, p.S);
				ans += c;
			}
		}
		cout << ans << endl;
		// dpite(ALL(ya)); dpite(ALL(xa));
		// cout << min(abs(xa[0]-xa.back()), abs(ya[0]-ya.back())) << endl;
	}
	return 0;
}
