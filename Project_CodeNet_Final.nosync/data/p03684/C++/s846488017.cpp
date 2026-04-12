//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
//#include<cstdio>//"scanf("%lf",&(double型変数));printf("%f",(double型変数));"
//#include<iomanip>//"cout<<fixed<<setprecision(n)<<sth<<endl;"
//#include<string>//"reverse(s's it,s's it)"
//#include<functional>//"greater<T>" "sort(a,a+n,greater<int>());""
//#include<cmath>//"abs" "sqrt"
//#include<numeric>//"accumulate(inputit,inputit,init,(optional) object)"
//#include<algorithm>//"lower_bound(it,it,v)" "next_permutation(a,a+n)"
//"reverse(v's it,v's it)"(v: vector)
//#include<cassert>//"assert(cond);": error if cond doesn't hold.
using namespace std;
#define pb push_back//also for STRING
#define fi first
#define sc second
#define mp make_pair
#define is insert//also use as v.is(v's it,w's it,w's it);
#define ps push//TMP//stack,(priority) queue,
#define fr front//TMP//queue//for priority, use top().
typedef long long ll;//not necessarily
typedef pair<int,int> pii;
typedef pair<pii,int> pt;

vector<int> par,rk;

void init(const int n){
	par.resize(n);
	rk.resize(n);
	for(int i=0;i<n;++i) par[i]=i;
	fill(rk.begin(),rk.end(),0);
}

int find(int x){
	if(par[x]==x){
		return x;
	}else{
		return par[x]=find(par[x]);
	}
}

void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y){
		return;
	}else if(rk[x]<rk[y]){
		par[x]=y;
	}else{
		par[y]=x;
		if(rk[x]==rk[y]){
			++rk[x];
		}
	}
}

bool same(int x,int y){
	return find(x)==find(y);
}

struct edge{
	int from,to,cost;
};

#define MAX_N 100000

vector<edge> es;
pt p[MAX_N];
int prv[MAX_N];

bool cmp_pt(pt p,pt q){
	if(p.fi.fi!=q.fi.fi) return p.fi.fi<q.fi.fi;
	else return p.fi.sc<q.fi.sc;
}

bool cmp_ed(edge e,edge f){
	return e.cost<f.cost;
}

int d(int i,int j){
	return min(abs(p[i].fi.fi-p[j].fi.fi),abs(p[i].fi.sc-p[j].fi.sc));
}

int main(){
	int n;
	scanf("%d\n",&n);
	for(int i=0;i<n;++i){
		cin>>p[i].fi.fi>>p[i].fi.sc;
		p[i].sc=i;
	}
	//printf("initializing points: fin\n");
	for(int k=0;k<2;++k){
		sort(p,p+n,cmp_pt);
		//printf("%d; sorting points: fin\n",k);
		for(int i=0;i<n;++i){
			if(i>0&&p[i].fi.fi==p[i-1].fi.fi){
				prv[i]=prv[i-1];
				es.pb((edge){p[i-1].sc,p[i].sc,0});
			}else prv[i]=i;
		}
		//printf("%d; spanning the 1st kind of edges: fin\n",k);
		for(int i=n-1;prv[i]>0;--i){
			int ub=prv[i]-1;
			if(p[ub].fi.sc<=p[i].fi.sc) es.pb((edge){p[ub].sc,p[i].sc,d(ub,i)});
			else{
				int lb=prv[ub];
				while(ub-lb>1){
					int mid=(ub+lb)/2;
					if(p[mid].fi.sc<=p[i].fi.sc) lb=mid;
					else ub=mid;
				}
				if(p[ub].fi.sc-p[i].fi.sc<p[i].fi.sc-p[lb].fi.sc) es.pb((edge){p[ub].sc,p[i].sc,d(ub,i)});
				else es.pb((edge){p[lb].sc,p[i].sc,d(lb,i)});
			}
		}
		//printf("%d; spanning the 2nd kind of edges: fin\n",k);
		for(int i=0;i<n;++i) swap(p[i].fi.fi,p[i].fi.sc);
		//printf("%d; fin\n",k);
	}
	sort(es.begin(),es.end(),cmp_ed);
	//printf("sorting edges: fin\n");
	init(n);
	//printf("initializing the unionfind: fin\n");
	int sc=0;
	//for(int j=0;j<es.size();++j){
	//	cout<<es[j].from<<" "<<es[j].to<<endl;
	//}
	for(int e=0,j=0;e<n-1;++j){
		int v=es[j].from,w=es[j].to;
		if(same(v,w)) continue;
		unite(v,w);
		sc+=es[j].cost;
		++e;
	}
	printf("%d\n",sc);
}