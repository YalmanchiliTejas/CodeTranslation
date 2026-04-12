#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <iostream>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

class node{
public:
	int sum[11];
	int lazy[11];
	node(){
		for(int i=0;i<10;i++){
			sum[i]=0;
			lazy[i]=0;
		}
	}
};

int n,q;
int f[100001],t[100001];
vector<int> G[100001];
bool used[100001];
node seg[1<<20];
int cnt=0;
int wid=1;

void dfs(int v){
	used[v]=true;
	f[v]=cnt++;
	for(int i=0;i<G[v].size();i++){
		if(!used[G[v][i]]){
			dfs(G[v][i]);
		}
	}
	t[v]=cnt++;
}

int tmp[11];

inline void lazy_evaluate_node(int k){
	memset(tmp,0,sizeof(tmp));
	for(int i=0;i<10;i++){
		tmp[seg[k].lazy[i]]+=seg[k].sum[i];
	}
	for(int i=0;i<10;i++){
		seg[k].sum[i]=tmp[i];
	}
	if(k+1<wid){
		for(int i=0;i<10;i++){
			tmp[i]=seg[k*2+1].lazy[i];
		}
		for(int i=0;i<10;i++){
			seg[k*2+1].lazy[i]=seg[k].lazy[tmp[i]];
		}
		for(int i=0;i<10;i++){
			tmp[i]=seg[k*2+2].lazy[i];
		}
		for(int i=0;i<10;i++){
			seg[k*2+2].lazy[i]=seg[k].lazy[tmp[i]];
		}
	}
	for(int i=0;i<10;i++){
		seg[k].lazy[i]=i;
	}
}

inline void lazy_update_node(int k){
	for(int i=0;i<10;i++){
		seg[k].sum[i]=seg[k*2+1].sum[i]+seg[k*2+2].sum[i];
	}
}

void add(int k,int a){
	k+=wid-1;
	seg[k].sum[0]+=a;
	while(k>0){
		k=(k-1)/2;
		seg[k].sum[0]=seg[k*2+1].sum[0]+seg[k*2+2].sum[0];
	}
}

void update(int f,int t,int a,int b,int k=0,int l=0,int r=wid){
	lazy_evaluate_node(k);
	if(r<=a || b<=l)return;
	if(a<=l && r<=b){
		seg[k].lazy[f]=t;
		lazy_evaluate_node(k);
		return;
	}
	update(f,t,a,b,k*2+1,l,(l+r)/2);
	update(f,t,a,b,k*2+2,(l+r)/2,r);
	lazy_update_node(k);
}

int query(int x,int y,int a,int b,int k=0,int l=0,int r=wid){
	lazy_evaluate_node(k);
	if(r<=a || b<=l)return 0;
	if(a<=l && r<=b){
		int res=0;
		for(int i=x;i<=y;i++){
			res+=seg[k].sum[i];
		}
		return res;
	}
	int vl=query(x,y,a,b,k*2+1,l,(l+r)/2);
	int vr=query(x,y,a,b,k*2+2,(l+r)/2,r);
	lazy_update_node(k);
	return vl+vr;
}

int main(void){
	scanf("%d%d",&n,&q);
	for(int i=0;i<n-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
	}
	memset(used,false,sizeof(used));
	dfs(0);
	while(wid<cnt+1)wid*=2;
	for(int i=0;i<wid*2-1;i++){
		for(int j=0;j<10;j++){
			seg[i].sum[j]=0;
		}
	}
	for(int i=0;i<n;i++){
		add(f[i],1);
	}
	for(int i=0;i<q;i++){
		int type,r,x,y;
		scanf("%d%d%d%d",&type,&r,&x,&y);
		if(type==1){
			int res=query(x,y,f[r],t[r]);
			printf("%d\n",res);
		}else{
			update(x,y,f[r],t[r]);
		}
	}
	return 0;
}