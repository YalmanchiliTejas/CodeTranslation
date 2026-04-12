#include<bits/stdc++.h>
#define N 100005
using namespace std;
bool cur1;
int n,ans,sze;
int a[N];
struct node{
	int x,id;
}Q[N];
inline bool cmp(node a,node b){
	return a.x<b.x;
}
inline void Rd(int &res){
	char c;res=0;
	while(c=getchar(),c<48);
	do res=(res<<3)+(res<<1)+(c^48);
	while(c=getchar(),c>47);
	return;
}
struct YDtree{
	#define ls p<<1
	#define rs p<<1|1
	int cnt[N<<2],mn[N<<2];
	inline void up(int p){
		mn[p]=max(mn[ls],mn[rs]);
	}
	void update(int l,int r,int x,int v,int p){
		if(l==r){
			cnt[p]+=v;
			if(!cnt[p])mn[p]=0;
			else mn[p]=l;
			return;
		}
		int mid=(l+r)>>1;
		if(mid>=x)update(l,mid,x,v,ls);
		else update(mid+1,r,x,v,rs);
		up(p);
	}
	int query(int l,int r,int L,int R,int p){
		if(L<=l&&r<=R)return mn[p];
		int mid=(l+r)>>1,res=2e9;
		if(mid>=L)res=query(l,mid,L,R,ls);
		if(mid<R)res=max(res,query(mid+1,r,L,R,rs));
		return res;
	}
}YD;
bool cur2;
int main(){
//	printf("%lf MB\n",(&cur2-&cur1)/1024.0/1024);
	Rd(n);
	for(int i=1;i<=n;i++)Rd(Q[i].x),Q[i].id=i;
	sort(Q+1,Q+n+1,cmp);
	Q[0].x=-2e9;
	for(int i=1;i<=n;i++){
		if(Q[i].x!=Q[i-1].x)a[Q[i].id]=++sze;
		else a[Q[i].id]=sze;
	}
	ans=n;
	for(int i=1;i<=n;i++){
		int o;
		if(a[i]==1)o=0;
		else o=YD.query(1,n,1,a[i]-1,1);
		if(o!=0){
			ans--;
			YD.update(1,n,o,-1,1);
		}
		YD.update(1,n,a[i],1,1);
	}
	printf("%d\n",ans);
	return 0;
}