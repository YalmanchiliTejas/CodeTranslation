#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;
//LLONG_MIN

//同じ座標があったときにどうするか？？？


struct edge {ll u,v,cost;};

bool comp(const edge&e1, const edge&e2){
	return e1.cost < e2.cost;
}

int par[1000001];
int find(int x){
	if(par[x]==x)return x;
	return par[x]=find(par[x]);
}
bool same(int x,int y){
	return find(x)==find(y);
}
void unite(int x,int y){
	x = find(x);
	y = find(y);
	if(x==y)return;
	par[x]=y;
}

int main(void){
	vector<edge> es;
	int E,N;
	ll ans=0;
	ll x[100001],y[100001];
	ll x2[100001],y2[100001];
	map<ll,ll> x_index;
	map<ll,ll> y_index;
	cin>>N;
	rep(i,N)par[i]=i;//union-find初期化
	E = (N-1)*2;
	rep(i,N){
		cin>>x[i]>>y[i];
		if( x_index.end() != x_index.find(x[i]) ){//先客がいた場合
			unite(x_index[x[i]],i);
		}
		if( y_index.end() != y_index.find(y[i]) ){//先客がいた場合
			unite(y_index[y[i]],i);
		}
		x_index[x[i]]=i;
		y_index[y[i]]=i;
		x2[i]=x[i];
		y2[i]=y[i];
	}
	sort(x2,x2+N);
	sort(y2,y2+N);
	rep(i,N-1){
		es.push_back((edge){x_index[x2[i]],x_index[x2[i+1]],abs(x2[i]-x2[i+1]) } );
		es.push_back((edge){y_index[y2[i]],y_index[y2[i+1]],abs(y2[i]-y2[i+1]) } );
	}
	sort(es.begin(),es.end(),comp);
	rep(i,E){
		edge e = es[i];
		if(!same(e.u,e.v)){
			unite(e.u,e.v);
			ans+=e.cost;
		}
	}

	cout<<ans<<endl;
	return 0;
}