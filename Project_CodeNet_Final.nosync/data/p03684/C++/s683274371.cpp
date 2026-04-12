#include<bits/stdc++.h>

#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pf push_front
#define pb2 pop_back
#define pf2 pop_front
#define line printf("\n")
#define pq priority_queue
#define rep(k,i,j) for(int k = (int)i;k<(int)j;k++)
#define repd(k,i,j) for(int k = (int)i;k>=(int)j;k--)
#define ll long long
#define ALL(a) a.begin(),a.end()
#define vi vector<int> 

using namespace std;

double EPS = 1e-9;
int INF = 1e9+7;;
long long INFLL = 1e17;
double pi = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

clock_t first_attempt = clock();
inline void cek_time(){
	clock_t cur = clock()- first_attempt;
	cerr<<"TIME : "<<(double) cur/CLOCKS_PER_SEC<<endl;
}
inline void OPEN (string s) {
  freopen ((s + ".in").c_str (), "r", stdin);
  freopen ((s + ".out").c_str (), "w", stdout);
}

//end of template

const int maxn =1e5+5;

int n;

vector<pii> edges;
pii arr[maxn];

int X(int a,int b){return arr[a].fi<arr[b].fi;}
int Y(int a,int b){return arr[a].se<arr[b].se;}

int val(pii a){return min(abs(arr[a.fi].fi-arr[a.se].fi),abs(arr[a.fi].se-arr[a.se].se));}
int cmp(pii a,pii b){return val(a)<val(b);}
int id[maxn];

int par[maxn];
int root(int a){if(par[a]==a)return a;return par[a] = root(par[a]);}
void join(int a,int b){
	a = root(a),b = root(b);
	if(a!=b)par[a] = b;
}
int main(){
	scanf("%d",&n);
	
	rep(k,0,n)scanf("%d%d",&arr[k].fi,&arr[k].se),id[k] = k;
	
	sort(id,id+n,X);
	rep(k,1,n)edges.pb(mp(id[k-1],id[k]));
	sort(id,id+n,Y);
	rep(k,1,n)edges.pb(mp(id[k-1],id[k]));
	
	sort(edges.begin(),edges.end(),cmp);
	ll ret = 0;
	rep(k,0,n)par[k] = k;
	for(pii a : edges){
		if(root(a.fi)!=root(a.se))join(a.fi,a.se),ret += val(a);
	}
	cout<<ret<<endl;
	return 0;
}
