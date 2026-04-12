#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll tag[800050],t[800050];
int n,m;
struct re{
	int l,r,v;
}a[200050];
void pushdown(int l,int r,int id){
	if (l==r||!tag[id])return;
	t[id<<1]+=tag[id];t[id<<1|1]+=tag[id];tag[id<<1]+=tag[id];tag[id<<1|1]+=tag[id];
	tag[id]=0;
}
void modify(int l,int r,int id,int ql,int qr,ll v){
	if (ql<=l&&r<=qr){t[id]+=v;tag[id]+=v;return;}
	int mid=(l+r)>>1;
	pushdown(l,r,id);
	if (ql<=mid)modify(l,mid,id<<1,ql,qr,v);
	if (qr>mid)modify(mid+1,r,id<<1|1,ql,qr,v);
	t[id]=max(t[id<<1],t[id<<1|1]);
}
ll query(int l,int r,int id,int x){
	if (r==x)return t[id];
	int mid=(l+r)>>1;
	if (mid<x)return max(t[id<<1],query(mid+1,r,id<<1|1,x));
	else return query(l,mid,id<<1,x);
}
bool cmp(re a,re b){return a.r<b.r;}
int main(){
	scanf("%d%d",&n,&m);n++;
	for (int i=1;i<=m;i++)scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].v),a[i].l++,a[i].r++;
	sort(a+1,a+m+1,cmp);
	int pos=1;
	for (int i=2;i<=n;i++){
		modify(1,n,1,i,i,query(1,n,1,i));
		while (a[pos].r==i)modify(1,n,1,a[pos].l,a[pos].r,a[pos].v),pos++;
	}
	printf("%lld",t[1]);
}