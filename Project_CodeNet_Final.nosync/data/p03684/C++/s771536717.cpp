//include
//------------------------------------------
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long ll;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

struct edge{
	int a;int b;int cost;
};
bool comp(edge& a, edge& b){
	return a.cost < b.cost;
}

int n;
int par[100008],rk[100008];
int x[100008],y[100008];
edge eds[200008];
set<int> s;
vector<PII> xs,ys,XS,YS;

void init(int m){
	REP(i,m){
		par[i]=i;
		rk[i]=0;
	}
}

int find(int i){
	return par[i] == i ? i : par[i] = find(par[i]);
}
bool same(int x, int y){
	return  find(x) == find(y);
}

void unite(int x, int y){
	x = find(x);
	y = find(y);
	if(x==y)return;
	if(rk[x]<rk[y]){
		par[y] = x;
	}else{
		par[x] = y;
		if(rk[x]==rk[y])rk[y]++;
	}
}

int main() {
	cin >> n;
	REP(i,n){
		cin >> x[i] >> y[i];
		xs.push_back(MP(x[i],i));
		ys.push_back(MP(y[i],i));
	}
	SORT(xs);SORT(ys);
//	reverse(ALL(xs));reverse(ALL(ys));
	int index=0;
	REP(i, n-1){
		eds[index++]=(edge){xs[i].second, xs[i+1].second, xs[i+1].first-xs[i].first};
		eds[index++]=(edge){ys[i].second, ys[i+1].second, ys[i+1].first-ys[i].first};
	}
	sort(eds, eds + index, comp);
	init(n);
	ll ans = 0;
	REP(i,index){
		edge ed = eds[i];
		if(!same(ed.a,ed.b)){
			ans += ed.cost;
			unite(ed.a, ed.b);
		}
	}
	cout << ans << endl;
	return 0;
}

