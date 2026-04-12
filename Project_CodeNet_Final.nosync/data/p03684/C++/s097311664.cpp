#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <functional>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <list>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
typedef pair<ll,P> PP2;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const ll INF = 1LL<<29;
const ll mod = 1e9+7;
#define rep(i,n) for(int (i)=0;(i)<(ll)(n);++(i))
#define repd(i,n,d) for(ll (i)=0;(i)<(ll)(n);(i)+=(d))
#define all(v) (v).begin(), (v).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset((m),(v),sizeof(m))
#define chmin(X,Y) ((X)>(Y)?X=(Y),true:false)
#define chmax(X,Y) ((X)<(Y)?X=(Y),true:false)
#define fst first
#define snd second
#define UNIQUE(x) (x).erase(unique(all(x)),(x).end())
template<class T> ostream &operator<<(ostream &os, const vector<T> &v){int n=v.size();rep(i,n)os<<v[i]<<(i==n-1?"":" ");return os;}

#define MAX_N 100010
struct UF {
	int par[MAX_N],rank[MAX_N];
	
	void init(int n){
		for(int i = 0; i < n; i++){
			par[i] = i;
			rank[i] = 0;
		}
	}
	
	int find(int x){
		if(par[x] == x){
			return x;
		}else{
			return par[x] = find(par[x]);
		}
	}
	
	void unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return;
		
		if(rank[x] < rank[y]){
			par[x] = y;
		}else{
			par[y] = par[x];
			if(rank[x] == rank[y]) rank[y]++;
		}
	}
	
	bool same(int x, int y){
		return find(x) == find(y);
	}
};

int main(){
	int n; cin>>n;
	vector<PP> v(n);
	rep(i, n){
		cin>>v[i].fst.fst>>v[i].fst.snd;
		v[i].snd = i;
	}
	UF uf;
	uf.init(n);
	sort(all(v));
	vector<PP2> d(2*n-2);
	rep(i, n-1) d[i] = PP2(v[i+1].fst.fst-v[i].fst.fst, P(v[i+1].snd, v[i].snd));
	rep(i, n) swap(v[i].fst.fst, v[i].fst.snd);
	sort(all(v));
	rep(i, n-1) d[i+n-1] = PP2(v[i+1].fst.fst-v[i].fst.fst, P(v[i+1].snd, v[i].snd));
	sort(all(d));
	ll res = 0;
	rep(i, 2*n-2){
		int u = d[i].snd.fst, v = d[i].snd.snd;
		if(!uf.same(u, v)){
			uf.unite(u, v);
			res += d[i].fst;
		}
	}
	cout<<res<<endl;
	return 0;
}
