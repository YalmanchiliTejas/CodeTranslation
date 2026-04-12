#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int par[5000];
int find(int x){
	if(par[x]==-1)return x;
	return par[x]=find(par[x]);
}
void unite(int x,int y){
	x=find(x);y=find(y);
	par[x]=y;
}
struct st{int a,b,c;};

int s[200000],t[200000];
int l[200000],r[200000];
vector<int>query[5000];

int main(){
	int n,m;scanf("%d%d",&n,&m);
	vector<st>v,u;
	rep(i,m){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);a--;b--;
		v.push_back({a,b,c});
	}
	sort(v.begin(),v.end(),[](st a,st b){return a.c<b.c;});
	memset(par,-1,sizeof(par));
	ll cnt=0;
	for(st&p:v){
		if(find(p.a)==find(p.b))continue;
		cnt+=p.c;unite(p.a,p.b);
		u.push_back(p);
	}
	int q;scanf("%d",&q);
	rep(i,q){
		scanf("%d%d",&s[i],&t[i]);s[i]--;t[i]--;
		l[i]=0;r[i]=n-1;
	}
	rep(i,15){
		rep(j,n-1)query[j].clear();
		rep(j,q){
			if(r[j]-l[j]>1)query[(l[j]+r[j])/2].push_back(j);
		}
		memset(par,-1,sizeof(par));
		rep(j,n-1){
			for(int k:query[j]){
				if(find(s[k])!=find(t[k]))l[k]=j;
				else r[k]=j;
			}
			unite(u[j].a,u[j].b);
		}
	}
	rep(i,q){
		printf("%lld\n",cnt-u[l[i]].c);
	}
}