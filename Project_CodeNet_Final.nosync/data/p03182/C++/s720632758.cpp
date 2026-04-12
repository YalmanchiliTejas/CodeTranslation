#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll input(){
	ll x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return f? -x:x;
}

const int N=2e5+7;

ll t[N<<2],lazy[N<<2];

void putdown(int rt){
	if(lazy[rt]){
		t[rt<<1]+=lazy[rt];
		t[rt<<1|1]+=lazy[rt];
		lazy[rt<<1]+=lazy[rt];
		lazy[rt<<1|1]+=lazy[rt];
		lazy[rt]=0;
	}
}

void put(int rt){
	t[rt]=max(t[rt<<1],t[rt<<1|1]);
}

ll query(int rt,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr) return t[rt];
	putdown(rt);
	int mid=(l+r)>>1;
	if(qr<=mid) return query(rt<<1,l,mid,ql,qr);
	if(mid<ql) return query(rt<<1|1,mid+1,r,ql,qr);
	return max(query(rt<<1,l,mid,ql,qr),query(rt<<1|1,mid+1,r,ql,qr));
}

void update(int rt,int l,int r,int ul,int ur,ll x){
	if(ul<=l&&r<=ur){t[rt]+=x,lazy[rt]+=x;return;}
	putdown(rt);
	int mid=(l+r)>>1;
	if(ul<=mid) update(rt<<1,l,mid,ul,ur,x);
	if(ur>mid) update(rt<<1|1,mid+1,r,ul,ur,x);
	put(rt);
}

struct opr{
	int l,r,c;
}a[N];
bool cmp(opr a,opr b){
	return a.r<b.r;
}

int main(){
	int n=input(),m=input();
	for(int i=1;i<=m;i++){
		a[i].l=input(),a[i].r=input(),a[i].c=input();
	}

	sort(a+1,a+1+m,cmp);

	ll p=0;

	for(int i=1;i<=n;i++){
		update(1,0,n,i,i,query(1,0,n,0,i-1));
		while(p<m&&a[p+1].r==i) p++,update(1,0,n,a[p].l,a[p].r,a[p].c);
	}
	printf("%lld\n",query(1,0,n,0,n));
}