#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
	int l,r,w;
	bool operator < (const struct node & n)const
	{
		return r<n.r;
	}
}NODE,*PNODE;
NODE a[200001];
long long t[1<<19],lazy[1<<19];
long long query(int index,int lb,int rb,int lq,int rq)
{
	if(lb==rb||lb==lq&&rb==rq)
		return t[index];
	if(lazy[index])
	{
		t[index<<1]+=lazy[index];
		t[index<<1|1]+=lazy[index];
		lazy[index<<1]+=lazy[index];
		lazy[index<<1|1]+=lazy[index];
		lazy[index]=0;
	}
	int mid=(lb+rb)>>1;
	if(rq<=mid)
		return query(index<<1,lb,mid,lq,rq);
	else if(lq>mid)
		return query(index<<1|1,mid+1,rb,lq,rq);
	else
		return max(query(index<<1,lb,mid,lq,mid),query(index<<1|1,mid+1,rb,mid+1,rq));
}
void update(int index,int lb,int rb,int lq,int rq,long long value)
{
	if(lb==lq&&rb==rq)
	{
		t[index]+=value;
		lazy[index]+=value;
		return;	
	}
	if(lazy[index])
	{
		t[index<<1]+=lazy[index];
		t[index<<1|1]+=lazy[index];
		lazy[index<<1]+=lazy[index];
		lazy[index<<1|1]+=lazy[index];
		lazy[index]=0;
	}
	int mid=(lb+rb)>>1;
	if(rq<=mid)
		update(index<<1,lb,mid,lq,rq,value);
	else if(lq>mid)
		update(index<<1|1,mid+1,rb,lq,rq,value);
	else
	{
		update(index<<1|1,mid+1,rb,mid+1,rq,value);
		update(index<<1,lb,mid,lq,mid,value);
	}		
	t[index]=max(t[index<<1],t[index<<1|1]);
}
int main()
{
	int i,n,m,k=1;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].w);
	sort(a+1,a+1+m);
	for(i=1;i<=n;i++)
	{
		update(1,0,n,i,i,query(1,0,n,0,i-1));
		while(a[k].r==i)
		{
			update(1,0,n,a[k].l,a[k].r,a[k].w);
			k++;
		}
	}
	printf("%lld",t[1]);
	return 0;
}