#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#include <iomanip>
#include <complex>
#include <bitset>
#include <stack>
using namespace std;
 
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define repl(i,s,n) for(int i=s; i<=n; ++i)
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define ktya(x) sort(all(x))
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 1e18
#define INFLL 1000000000000000007LL
#define SIZE 200105
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define mind(a,b) (a>b?b:a)
#define maxd(a,b) (a>b?a:b)
#define PI (acos(-1))
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
typedef pair<int,ll> pill; typedef pair<ll,int> plli; 
typedef pair<double, int> pdi;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
typedef complex<double> P;
//ll MOD = 1000000007;
ll MOD=998244353;
typedef ll Weight;
struct Edge {
	int src, dst;
	Weight weight;
};
bool operator < (const Edge &e, const Edge &f) {
	return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
	e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
vector<pair<ll, pii> > data;
vi tree[114514];
pii depth[114514];
queue<int> Q;
int iro[114514]={0};
int oya[114514];
void dfs(int hoge,int from){
	oya[hoge]=from;
	if(hoge!=0){
		depth[hoge].first=depth[from].first+1;
	}
	rep(i,tree[hoge].size()){
		int nex=tree[hoge][i];
		if(depth[nex].first==-1){
			dfs(nex,hoge);
		}
	}
}
int N;
void outtree(){
	rep(i,N){
		cout<<i+1<<" "<<iro[i]<<endl;
	}
	
}
int main(){
	cin>>N;
	rep(i,N)depth[i]=mp(-1,i);
	rep(i,N-1){
		int x,y;
		cin>>x>>y;
		x--;y--;
		tree[x].pb(y);
		tree[y].pb(x);
	}
	// 1:white 2:black
	depth[0]=mp(0,0);
	dfs(0,-1);
	sort(depth,depth+N);
	reverse(depth,depth+N);
	for(int i=0;i<N;i++){
		int koko=depth[i].second;
		if(iro[koko]==0){
			if(oya[koko]==-1){
				iro[koko]=1;
			}else if(iro[oya[koko]]==0){
				iro[koko]=2;
				iro[oya[koko]]=1;
			}else{
				cout<<"First"<<endl;
				//outtree();
				return 0;
			}
		}
	}
	//outtree();
	rep(i,N){
		bool flag=true;
		if(iro[i]==1){
			rep(j,tree[i].size()){
				if(iro[tree[i][j]]!=1)flag=false;
			}
			if(flag){
				cout<<"First"<<endl;
				return 0;
			}
		}
	}
	cout<<"Second"<<endl;
}
