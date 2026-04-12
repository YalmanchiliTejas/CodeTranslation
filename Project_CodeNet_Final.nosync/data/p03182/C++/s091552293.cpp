#include<cstdio>
#include<cstring>
#include<algorithm>
const int MAXN=200010;

inline long long max(long long x,long long y){
	return x>y?x:y;
}
struct node{
	int l,r;
	long long val,tag;
}tr[MAXN<<2];
void upd(int o){
	tr[o].val=max(tr[o<<1].val,tr[o<<1|1].val);
}
void pushdown(int o){
	if(tr[o].tag){
		tr[o<<1].tag+=tr[o].tag;
		tr[o<<1].val+=tr[o].tag;
		tr[o<<1|1].tag+=tr[o].tag;
		tr[o<<1|1].val+=tr[o].tag;
		tr[o].tag=0;
	}
}
void build(int o,int l,int r){
	// puts("233");
	tr[o].l=l;tr[o].r=r;
	if(l>=r)
		return;
	int mid=(l+r)>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
}
void update(int o,int lt,int rt,long long v){
	// printf("%d %d %d\n",o,lt,rt);
	int l=tr[o].l,r=tr[o].r;
	if(lt<=l&&r<=rt){
		tr[o].tag+=v;
		tr[o].val+=v;
		return;
	}
	pushdown(o);
	int mid=(l+r)>>1;
	if(lt<=mid)
		update(o<<1,lt,rt,v);
	if(mid+1<=rt)
		update(o<<1|1,lt,rt,v);
	upd(o);
}
long long query(int o,int lt,int rt){
	// puts("666");
	int l=tr[o].l,r=tr[o].r;
	if(l==lt&&r==rt)
		return tr[o].val;
	pushdown(o);
	int mid=(l+r)>>1;
	if(rt<=mid)//Though it's impossible that lt>=mid+1
		return query(o<<1,lt,rt);
	else if(lt>=mid+1)
		return query(o<<1|1,lt,rt);
	else
		return max(query(o<<1,lt,mid),query(o<<1|1,mid+1,rt));
}

struct event{
	int l,r;
	long long a;
	bool operator<(const event &rhs)const{
		return r<rhs.r;
	}
}p[MAXN];
int n,m;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%lld",&p[i].l,&p[i].r,&p[i].a);
	std::sort(p+1,p+m+1);
	build(1,1,n);
	int tot=1;
	for(int i=1;i<=n;i++){
		update(1,i,i,query(1,1,i));
		while(p[tot].r<=i&&tot<=m){
			update(1,p[tot].l,p[tot].r,p[tot].a);
			tot++;
		}
		// if(i==5)return 0;
	}
	printf("%lld\n",max(0,tr[1].val));
	return 0;
}