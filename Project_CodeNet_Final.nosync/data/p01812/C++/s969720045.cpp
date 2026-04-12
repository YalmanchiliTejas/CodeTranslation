#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<29;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-9;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

class Union_Find_Tree{
	public:
	vi p,r,s;
	Union_Find_Tree(int n){
		p=r=vi(n);
		s=vi(n,1);
		for(int i=0;i<n;i++) p[i]=i;
	}
	int Par(int x){
		if(p[x]==x) return x;
		return p[x]=Par(p[x]);
	}
	int Size(int x){return s[Par(x)];}
	bool Unite(int x,int y){
		x=Par(x);
		y=Par(y);
		if(x==y) return 0;
		if(r[x]<r[y]){
			p[x]=y;
			s[y]+=s[x];
		}
		else{
			p[y]=x;
			s[x]+=s[y];
			if(r[x]==r[y]) r[x]++;
		}
		return 1;
	}
	bool Same(int x,int y){return Par(x)==Par(y);}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	vi a(m),b(n,-1);
	vvi g(n,vi(k));
	for(int i=0;i<m;i++){
		cin>>a[i];
		a[i]--;
		b[a[i]]=i;
	}
	for(int i=0;i<n;i++) for(int j=0;j<k;j++){
		cin>>g[i][j];
		g[i][j]--;
	}
	queue<P> q;
	q.push({(1<<m)-1,0});
	vi dis(1<<m,inf);
	dis[(1<<m)-1]=0;
	while(!q.empty()){
		P p=q.front();q.pop();
		int S=p.first,d=p.second;
		for(int i=0;i<k;i++){
			int T=0;
			for(int j=0;j<m;j++) if(S&1<<j){
				int nx=b[g[a[j]][i]];
				if(nx>=0) T|=1<<b[g[a[j]][i]];
			}
//			cout<<S<<' '<<T<<endl;
			if(dis[T]==inf){
				q.push({T,d+1});
				dis[T]=d+1;
			}
		}
	}
//	for(auto i:dis) cout<<i<<' ';cout<<endl;
	cout<<dis[0]<<endl;
}
