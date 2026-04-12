#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<assert.h>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef ll Def;
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
#define mt make_tuple
typedef tuple<pii,int,int> tp;
typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
const double PI=acos(-1);
const double EPS=1e-7;
Def inf=sizeof(Def)==sizeof(long long)?9e18:1e9;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
struct UnionFind{
    vector<int> data;
    UnionFind(int size) : data(size, -1) {}
    bool unionSet(int x,int y){
        x=root(x);y=root(y);
        if(x==y)return 0;
        if(data[y]<data[x])swap(x,y);
        data[x]+=data[y],data[y]=x;
        return 1;
    }
    bool findSet(int x,int y){
        return root(x)==root(y);
    }
    int root(int x){
        return data[x]<0 ? x : data[x]=root(data[x]);
    }
    int size(int x){
        return -data[root(x)];
    }
};
class KRK{//c++11
	public:
	struct edge{
		int from,to,cost;
	};
	vector<edge>G;
	int n;
	KRK(int size){
		n=size;
	}
	void add_edge(int a,int b,int c){
		edge e={a,b,c};
		G.pb(e);
	}
	int krk(){
		int sum=0;
		sort(all(G),[](edge a,edge b){
			return a.cost<b.cost;
		});
		UnionFind uf(n);
		rep(i,G.size()){
			edge e=G[i];
			if(!uf.findSet(e.from,e.to)){
				sum+=e.cost;
				uf.unionSet(e.from,e.to);
			}
		}
		return sum;
	}
};
int main(){
	int n;
	cin>>n;
	KRK krk(n);
	vip in(n);
	rep(i,n){
		int a,b;
		cin>>a>>b;
		in[i]={a,{i,b}};
//		krk.add_edge(a,b,c);
	}
	sort(all(in));
	rep(i,n-1)krk.add_edge(in[i].second.first,in[i+1].second.first,in[i+1].first-in[i].first);
	rep(i,n)swap(in[i].first,in[i].second.second);
	sort(all(in));
	rep(i,n-1)krk.add_edge(in[i].second.first,in[i+1].second.first,in[i+1].first-in[i].first);
	cout<<krk.krk()<<endl;
}









