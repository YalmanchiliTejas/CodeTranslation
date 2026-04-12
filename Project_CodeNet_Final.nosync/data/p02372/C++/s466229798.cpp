#include <bits/stdc++.h>

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
template<class T> inline T sqr(T x) {return x*x;}

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;

#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define each(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define exist(s,e) ((s).find(e)!=(s).end())
#define range(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  range(i,0,n)
#define clr(a,b) memset((a), (b) ,sizeof(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;


const double eps = 1e-10;
const double pi  = acos(-1.0);
const ll INF =1LL << 62;
const int inf =1 << 29;

const int vmax=100010;
struct node{ll to,cost;};

vector<node> graph[vmax];

ll dist[vmax];
ll cmax[vmax];
int ans[vmax];

void tree_height(int n){
	function<void(int,int,int)> dfs=[&dfs](int v,int p,ll c){
		dist[v]=c;
		for(auto &e:graph[v]) if(e.to!=p) dfs(e.to,v,c+e.cost);
	};
	dfs(0,-1,0LL);
	int u=max_element(dist,dist+n)-dist;
	dfs(u,-1,0LL);
	int v=max_element(dist,dist+n)-dist;

	function<void(int,int,ll,int)> dfs2=[&dfs2](int v,int p,ll c,int s){
		if((cmax[v]<c)||(cmax[v]==c&&ans[v]>s)) cmax[v]=c,ans[v]=s;
		for(auto &e:graph[v]) if(e.to!=p) dfs2(e.to,v,c+e.cost,s);
	};
	dfs2(u,-1,0LL,u);
	dfs2(v,-1,0LL,v);
}

int main(void){
	int n;
	scanf("%d",&n);
	rep(i,n-1){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		graph[a].pb({b,c});
		graph[b].pb({a,c});
	}
	tree_height(n);
	rep(i,n) printf("%d\n",cmax[i]);
	return 0;
}