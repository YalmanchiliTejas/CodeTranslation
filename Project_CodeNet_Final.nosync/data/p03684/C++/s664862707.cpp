#include<map>
#include<set>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<vector>
#include<complex>
#include<cstdlib>
#include<cstring>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
 
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
 
using namespace std;
 
#define int long long
//typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      P;
typedef pair<int,P> PP;
 
struct edge{ int u,v,cost; };
 
const int INF=1e+9;
const double EPS=1e-9;
const int MOD=1000000007;
 
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int par[100000];
int rnk[100000];

bool comp(const edge& e1, const edge& e2){
	return e1.cost < e2.cost;
}

void init(int n){
	for(int i = 0;i < n;i++){
		par[i] = i;
		rnk[i] = 0;
	}
}

int find(int x){
	if(par[x] == x) return x;
	else return par[x] = find(par[x]);
}

void unite(int x,int y){
	x = find(x);
	y = find(y);
	if(x == y) return;
	if(rnk[x] < rnk[y]){
		par[x] = y;
	}else{
		par[y] = x;
		if(rnk[x] == rnk[y]) rnk[x]++;
	}
}

bool same(int x,int y){
	return find(x) == find(y);
}

signed main(){
	int n,x[100000],y[100000];
	vector<PP> a,b;
	vector<edge> es;
	cin >> n;
	init(n);
	for(int i = 0;i < n;i++){
		cin >> x[i] >> y[i];
		a.push_back(mp(x[i],mp(y[i],i)));
		b.push_back(mp(y[i],mp(x[i],i)));
	}
	sort(all(a));
	sort(all(b));
	for(int i = 0;i < n - 1;i++){
		es.push_back({a[i].second.second,a[i + 1].second.second,a[i + 1].first - a[i].first});
		es.push_back({b[i].second.second,b[i + 1].second.second,b[i + 1].first - b[i].first});
	}
	sort(all(es),comp);
	int ans = 0;
	for(int i = 0;i < es.size();i++){
		edge e = es[i];
		if(!same(e.u,e.v)){
			unite(e.u,e.v);
			ans += e.cost;
		}
	}
	cout << ans << endl;
	return 0;
}