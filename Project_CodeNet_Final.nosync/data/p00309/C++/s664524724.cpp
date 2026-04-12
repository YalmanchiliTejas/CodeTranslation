#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define REACH cerr<<"reached line "<<__LINE__<<endl
#define DBG(x) cerr<<"line "<<__LINE__<<" "<<#x<<":"<<x<<endl

using uint=unsigned int;
using ll=long long;
using pii=pair<int,int>;
using vi=vector<int>;
using ld=long double;

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"[";
	REP(i,(int)v.size()){
		if(i)os<<",";
		os<<v[i];
	}
	os<<"]";
	return os;
}

int read(){
	int i;
	scanf("%d",&i);
	return i;
}

template<class T>
void chmax(T& a,T b){
	a=max(a,b);
}

template<class T>
void chmin(T& a,T b){
	a=min(a,b);
}

template<class T>
void ResetVector(vector<T>& v,int n,const T& t){
	v.clear();
	v.resize(n,t);
}

const int mod=1000000007;
template<class T,class U>
void add(T& a,U b){
	a=((ll)a+b)%mod;
}

template<>
void add(int& a,int b){
	a+=b;
	if(a>=mod)a-=mod;
}

template<class T,class U>
void sub(T& a,U b){
	a=((ll)a-b%mod+mod)%mod;
}

template<>
void sub(int& a,int b){
	a-=b;
	if(a<0)a+=mod;
}

template<class T,class U>
void mult(T& a,U b){
	a=((ll)a*b)%mod;
}

ll modPow(ll a,ll p){
	ll s=1;
	REP(i,30){
		if((p>>i)&1)
			mult(s,a);
		mult(a,a);
	}
	return s;
}

ll modInv(ll a){
	return modPow(a,mod-2);
}

template<class T>
ll DetMod(vector<vector<T>> mat){
	int n=mat.size();
	ll det=1;
	REP(i,n){
		FOR(j,i+1,n)if(mat[j][i]!=0){
			swap(mat[i],mat[j]);
			det=mod-det;
			break;
		}
		if(mat[i][i]==0)
			return 0;
		FOR(j,i+1,n){
			ll p=mat[j][i];
			mult(p,modInv(mat[i][i]));
			FOR(k,i,n)
				sub(mat[j][k],mat[i][k]*p);
		}
	}
	REP(i,n)mult(det,mat[i][i]);
	return det;
}

namespace MatrixTreeTheorem{
	//given graph should be connected
	vector<vi> mat;
	void Init(int n){
		ResetVector(mat,n,vi(n,0));
	}
	void AddEdge(int a,int b){
		mat[a][b]--;
		mat[b][a]--;
		mat[a][a]++;
		mat[b][b]++;
	}
	ll Calc(){
		int n=mat.size()-1;
		mat.resize(n);
		REP(i,n){
			mat[i].resize(n);
			REP(j,n)
				add(mat[i][j],mod);
		}
		return DetMod(mat);
	}
}

namespace NumberOfSpanningForest{
	vector<vi> graph;
	vector<pii> es;
	vi ord;
	void Init(int n){
		ResetVector(graph,n,vi());
		ResetVector(ord,n,-1);
	}
	void AddEdge(int a,int b){
		graph[a].PB(b);
		graph[b].PB(a);
		es.PB(MP(a,b));
	}
	ll Calc(){
		ll ret=1;
		for(auto e:es)if(ord[e.first]==-1){
			vector<pii> tmp;
			int idx=0;
			queue<int> q;
			q.push(e.first);
			ord[e.first]=idx++;
			while(!q.empty()){
				int v=q.front();q.pop();
				for(auto to:graph[v])if(ord[to]==-1){
					ord[to]=idx++;
					q.push(to);
				}else if(ord[to]<ord[v])
					tmp.PB(MP(v,to));
			}
			MatrixTreeTheorem::Init(idx);
			for(auto t:tmp)
				MatrixTreeTheorem::AddEdge(ord[t.first],ord[t.second]);
			mult(ret,MatrixTreeTheorem::Calc());
		}
		for(auto e:es){
			graph[e.first].clear();
			graph[e.second].clear();
			ord[e.first]=-1;
			ord[e.second]=-1;
		}
		es.clear();
		return ret;
	}
}

struct UnionFind{
	vi rank,par;
	void Init(int n){
		ResetVector(rank,n,0);
		ResetVector(par,n,-1);
	}
	int Find(int i){
		return par[i]==-1?i:(par[i]=Find(par[i]));
	}
	bool Same(int a,int b){
		return Find(a)==Find(b);
	}
	bool Unite(int a,int b){
		a=Find(a);
		b=Find(b);
		if(a==b)
			return false;
		if(rank[a]<rank[b])
			swap(a,b);
		par[b]=a;
		if(rank[a]==rank[b])
			rank[a]++;
		return true;
	}
} uf,uf2;

struct Edge{
	int a,b,d;
	bool operator<(const Edge& rhs)const{
		return d<rhs.d;
	}
};

int main(){
	int n=read(),m=read(),dist;
	vector<Edge> es;
	REP(i,m){
		int a=read()-1,b=read()-1,d=read();
		es.PB(Edge{a,b,d});
	}
	sort(es.begin(),es.end());
	uf.Init(n);
	int cmp=n;
	for(auto e:es)
		if(uf.Unite(e.a,e.b))
			if(--cmp==1){
				dist=e.d;
				break;
			}
	uf.Init(n);
	for(auto e:es)if(dist>e.d)
		uf.Unite(e.a,e.b);
	map<int,int> idx;
	REP(i,n)
		idx[uf.Find(i)]=0;
	int s=0;
	for(auto& kv:idx)
		kv.second=s++;
	int ans=0;
	NumberOfSpanningForest::Init(n);
	FOR(bits,1,(1<<s)-1){
		auto get=[&](int a){
			return (bits>>idx[uf.Find(a)])&1;
		};
		uf2.Init(n);
		int k=n;
		for(auto e:es)if(get(e.a)==get(e.b))
			if(uf2.Unite(e.a,e.b))
				k--;
		if(k!=2)
			continue;
		for(auto e:es)if(get(e.a)==get(e.b))
			NumberOfSpanningForest::AddEdge(e.a,e.b);
		add(ans,NumberOfSpanningForest::Calc());
	}
	cout<<dist<<" "<<ans<<endl;
}