#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
int n,m;
int tl[3100005],tr[3100005];
ll val[3100005],tag[3100005];
void build(int x,int l,int r){
	tl[x]=l,tr[x]=r;
	if(l==r){
		return ;
	}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build((x<<1)|1,mid+1,r);
}
void pushdown(int x){
	if(tag[x]){
		tag[x<<1]+=tag[x];
		val[x<<1]+=tag[x];
		tag[(x<<1)|1]+=tag[x];
		val[(x<<1)|1]+=tag[x];
		tag[x]=0;
	}
}
void modify(int x,int l,int r,ll v){
	int lc=tl[x],rc=tr[x],mid=(lc+rc)>>1;
	if(lc>=l&&rc<=r){
		tag[x]+=v;
		val[x]+=v;
		return ;
	}
	pushdown(x);
	if(l<=mid){
		modify(x<<1,l,r,v);
	}
	if(r>mid){
		modify((x<<1)|1,l,r,v);
	}
	val[x]=max(val[x<<1],val[(x<<1)|1]);
}
ll query(int x,int p){
	int lc=tl[x],rc=tr[x],mid=(lc+rc)>>1;
	if(rc==p){
		return val[x];
	}
	pushdown(x);
	if(p<=mid){
		return query(x<<1,p);
	}
	else{
		return max(val[x<<1],query((x<<1)|1,p));
	}
}
struct node{
	int l,r;
	ll v;
}b[3100005];
bool cmp(node a,node b){
	return a.r<b.r;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>b[i].l>>b[i].r>>b[i].v;
	}
	sort(b+1,b+1+m,cmp);
	build(1,1,n);
	int cnt=1;
	for(int i=1;i<=n;++i){
		modify(1,i,i,query(1,i));
		while(b[cnt].r==i){
			modify(1,b[cnt].l,b[cnt].r,b[cnt].v);
			cnt++;
		}
	}
	cout<<max(0ll,val[1])<<'\n';
	return 0;
}