#include <bits/stdc++.h>
using namespace std;
typedef struct range
{
	int l,r,num;
	bool operator < (const struct range & t)const 
	{
		return r<t.r;
	}
}RANGE,*PRANGE;
RANGE arr[1<<18];
long long tree[1<<19],lazy[1<<19];
long long search(int index,int lb,int rb,int lq,int rq)
{
	if(lb==rb||(lb==lq&&rb==rq))
		return tree[index];
	if(lazy[index])
	{
		tree[index<<1]+=lazy[index];
		tree[index<<1|1]+=lazy[index];
		lazy[index<<1]+=lazy[index];
		lazy[index<<1|1]+=lazy[index];
		lazy[index]=0;
	}
	int mid=(lb+rb)>>1;	
	if(lq>mid)
		return search(index<<1|1,mid+1,rb,lq,rq);
	else if(rq<=mid)
		return search(index<<1,lb,mid,lq,rq);
	else
		return max(search(index<<1|1,mid+1,rb,mid+1,rq),search(index<<1,lb,mid,lq,mid));
}
void update(int index,int lb,int rb,int lq,int rq,long long value)
{
	if(lb==lq&&rb==rq)
	{
		tree[index]+=value;
		lazy[index]+=value;
		return;
	}
	if(lazy[index])
	{
		tree[index<<1]+=lazy[index];
		tree[index<<1|1]+=lazy[index];
		lazy[index<<1]+=lazy[index];
		lazy[index<<1|1]+=lazy[index];
		lazy[index]=0;
	}
	int mid=(lb+rb)>>1;
	if(lq>mid)
		update(index<<1|1,mid+1,rb,lq,rq,value);
	else if(rq<=mid)
		update(index<<1,lb,mid,lq,rq,value);
	else
	{
		update(index<<1|1,mid+1,rb,mid+1,rq,value);
		update(index<<1,lb,mid,lq,mid,value);
	}	
	tree[index]=max(tree[index<<1],tree[index<<1|1]);
}
int main()
{
	int n,m,i,cnt;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
		scanf("%d %d %d",&arr[i].l,&arr[i].r,&arr[i].num);
	sort(arr,arr+m);
	cnt=0;
	for(i=1;i<=n;i++)
	{
		update(1,0,n,i,i,search(1,0,n,0,i-1));
		while(i==arr[cnt].r&&cnt<m)
		{
			update(1,0,n,arr[cnt].l,arr[cnt].r,arr[cnt].num);
			cnt++;
		}
	}
	printf("%lld",search(1,0,n,0,n));
	return 0;
}