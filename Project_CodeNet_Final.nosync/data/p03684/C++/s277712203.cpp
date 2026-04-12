#include <iostream>
#include <queue>
#include <assert.h>   
#include <vector>
#include <algorithm>
#include <time.h>
#include <numeric>
#include <string>
#include <cstring>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <numeric>
#include <deque>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <cstdio>
using namespace std;


//#define double long double
#define int long long
//#define int unsigned long long

#define ll long long
#define ld long double 
#define pi pair<int, int> 
#define pl pair<ll,ll>  
#define pd pair<ld,ld> 
#define str string  
#define mp make_pair
#define vi vector<int> 
#define vl vector<ll> 
#define vd vector<ld> 
#define vs vector<str> 
#define vpi vector<pi> 
#define vpl vector<pl> 
#define vpd vector<pd> 
#define si set<int> 
#define FF(i,j,n) for(signed i=j;i<=n;i++)  
#define DD(i,j,n) for(signed i=j;i>=n;i--) 
#define F(i,j,n) for(signed i=j;i<n;i++)   
#define D(i,j,n) for(signed i=j;i>n;i--) 
#define mem(a,b) memset(a,b,sizeof(a))
#define ndl cout << endl
#define ull unsigned long long 

const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;


#define sz(x) (signed)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back() 
#define fi first
#define se second
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound 
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

//math


const int mod = 1e9 + 7;

ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
int pct(int x) { return __builtin_popcount(x); } 
int bit(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
int cdiv(int a, int b) { return a/b+!(a<0||a%b == 0); } // division of a by b rounded up, assumes b > 0 


//DEBUG, compile with -DLOCAL
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
  cerr << to_string(h); if (sizeof...(t)) cerr << ", ";
  DBG(t...); }
#ifdef LOCAL 
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define HERE cout << "===GOTHERE===" << endl
#else
#define dbg(...) 42
#define HERE 42
#endif


 /* ============== END OF HEADER ============== */





const int maxn = 1e5*3+20;

int f[maxn];

int n,_,q,k;

struct P{
	int x; int y; int id;
};
vector<P> pts;
vector<P> byx;
vector<P> byy;

struct Edge{
	int fr; int to; int w;
};
vector<Edge> edges;


int dist(P p1, P p2){
	return min(abs(p1.x - p2.x), abs(p1.y - p2.y));
}

int find(int x){
    if(f[x]==x)return x;
    return f[x]=find(f[x]);
}
void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y)return;
    f[x]=y;
}

void solve(){
	cin >> n;
	FF(i,1,n){
		int t1,t2; cin >> t1 >> t2;
		pts.eb((P){t1,t2,i});
	}
	byx = pts;
	byy = pts;
	sort(all(byx), [](P p1, P p2){
		return p1.x < p2.x;
	});
	sort(all(byy), [](P p1, P p2){
		return p1.y < p2.y;
	});

	//build edges
	F(i,0,sz(byx)){
		P curr = byx[i];
		if(i-1 >= 0){
			P lft = byx[i-1];
			Edge ne = (Edge){curr.id, lft.id, dist(lft,curr)};
			edges.eb(ne);
		}
		if(i+1 < sz(byx)){
			P rt = byx[i+1];
			Edge ne = (Edge){curr.id, rt.id, dist(rt,curr)};
			edges.eb(ne);
		}
	}
	F(i,0,sz(byy)){
		P curr = byy[i];
		if(i-1 >= 0){
			P lft = byy[i-1];
			Edge ne = (Edge){curr.id, lft.id, dist(lft,curr)};
			edges.eb(ne);
		}
		if(i+1 < sz(byy)){
			P rt = byy[i+1];
			Edge ne = (Edge){curr.id, rt.id, dist(rt,curr)};
			edges.eb(ne);
		}
	}

	for(int i = 0; i < n; i++){
		f[i] = i;
	}
	sort(all(edges), [](Edge e1, Edge e2){
		return e1.w < e2.w;
	});	
	int sum = 0;
	dbg(sz(edges));
	for(Edge te : edges){
		if(find(te.fr) != find(te.to)){
			f[find(te.fr)] = f[find(te.to)];
			sum += te.w;
		}
	}
	cout << sum;


}

signed main(){
  //clock_t t1 = clock();  
	IOS
	solve();
  
  //cout << "THE ALGORITHM TOOK: " << (clock() - t1) * 1.0 / CLOCKS_PER_SEC * 1000 << "ms"<< endl;
	return 0;
}