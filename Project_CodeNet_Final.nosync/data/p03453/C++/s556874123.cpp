// g++ -std=c++11 a.cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<unordered_map>
#include<utility>
#include<cmath>
#include<random>
#include<cstring>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<assert.h>
#include<typeinfo>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define FOR(i,a) for(auto i:a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
#define show1d(v) rep(i,v.size())cout<<" "<<v[i];cout<<endl<<endl;
#define show2d(v) rep(i,v.size()){rep(j,v[i].size())cout<<" "<<v[i][j];cout<<endl;}cout<<endl;
using namespace std;
//kaewasuretyuui
typedef long long ll;
#define int ll
typedef int Def;
typedef pair<Def,Def> pii;
typedef vector<Def> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<Def,pii> pip;
typedef vector<pip>vip;
//#define mt make_tuple
//typedef tuple<int,int,int> tp;
//typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
//template<class C>constexpr int size(const C &c){return (int)c.size();}
//template<class T,size_t N> constexpr int size(const T (&xs)[N])noexcept{return (int)N;}
const double PI=acos(-1);
const double EPS=1e-9;
Def inf = sizeof(Def) == sizeof(long long) ? 2e18 : 1e9+10;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
ll MOD=1000000007;
class DIJ{
	public:
	struct edge{
		int to,cost;
	};
	vector<vector<edge> >G;
	int n;
	vi d,co;//distance
	DIJ(int size){
		n=size;
		G=vector<vector<edge> >(n);
	}
	void add_edge(int a,int b,int c){
		edge e={b,c},ee={a,c};
		G[a].pb(e);
		G[b].pb(ee);
	}
	void dij(int s){
		d=vi(n,inf);
		co=vi(n);
		d[s]=0;
		co[s]=1;
		priority_queue<pii>q;
		q.push(pii(0,s));
		while(!q.empty()){
			pii p=q.top();
			q.pop();
			int pos=p.second,cost=-p.first;
			if(cost>d[pos])continue;
			rep(i,G[pos].size()){
				edge e=G[pos][i];
				int to=e.to;
				int nowcost=cost+e.cost;
				if(nowcost<d[to]){
					d[to]=nowcost;
					co[to]=co[pos];
					q.push(pii(-d[to],to));
				}else if(nowcost==d[to])
					(co[to]+=co[pos])%=MOD;
			}
		}
	}
};
signed main(){
	int n,m,s,t;
	cin>>n>>m>>s>>t;s--;t--;
	DIJ dij(n);
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		a--;b--;
		dij.add_edge(a,b,c);
	}
	dij.dij(s);
	vi sd=dij.d,sco=dij.co;
	dij.dij(t);
	vi td=dij.d,tco=dij.co;
	
	int out=sco[t]*sco[t]%MOD;
	rep(i,n)if(sd[i]+td[i]==sd[t]&&sd[i]==td[i])(out+=MOD-(sco[i]*tco[i]%MOD)*(sco[i]*tco[i]%MOD)%MOD)%=MOD;
	rep(i,n)rep(j,dij.G[i].size())if(sd[i]+dij.G[i][j].cost+td[dij.G[i][j].to]==sd[t]&&sd[i]*2<sd[t]&&td[dij.G[i][j].to]*2<sd[t])(out+=MOD-(sco[i]*tco[dij.G[i][j].to]%MOD)*(sco[i]*tco[dij.G[i][j].to]%MOD)%MOD)%=MOD;
	cout<<out<<endl;
}















