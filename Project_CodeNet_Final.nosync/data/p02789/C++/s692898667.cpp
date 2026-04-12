#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <set>
#include <functional>
#include <cmath>


//マクロ
/*動かない・・・
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _roverload3(_1,_2,_3,name,...) name
#define _rrep(i,n) repi(i,0,n)
#define rrepi(i,a,b) for(int i=int(a);i<int(b);++i)
#define RREP(...) _roverload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)
//*/
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
#define REPS(i,n) for(int i=1; i<=(int)(n); ++i)
#define RREP(i,n) for(int i=(int)(n)-1; i>=0; --i)
#define RREPS(i,n) for(int i=(int)(n); i>0; --i)
#define FOR(i,s,e) for(int i=(int)(s); i<(int)(e); ++i)
#define RFOR(i,s,e) for(int i=(int)(e)-1; i>=(int)(s); --i)
//*/
#define All(a) (a).begin(),(a).end()
#define dump(x)  cerr << #x << " = " << (x) << endl;

//定数
#define INF 1e9
#define MOD (int)(1e9+7)

typedef long long ll;
typedef unsigned long long ull;
/*
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
//*/
using namespace std;
using Graph = vector<vector<int>>;

//とりあえず書いておく変数
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

//今回の変数
int n, m;

//使用する関数
template<class T>bool chmax(T &a, const T &b) {
	if (a < b) { a = b; return 1; }
	return 0;
}
template<class T>bool chmin(T &a, const T &b) {
	if (a > b) { a = b; return 1; }
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	cout << ((n == m) ? "Yes" : "No" )<< endl;
}