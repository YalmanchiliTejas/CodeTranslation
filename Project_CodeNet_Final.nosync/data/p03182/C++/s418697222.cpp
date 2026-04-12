#include"bits/stdc++.h"
using namespace std;
typedef struct range
{
	int left;
	int right;
	int value;
	bool operator < (const struct range & t)const
	{
		return right<t.right;
	}
}RANGE,*PRANGE;
int n,m;
RANGE arr[1<<18];
long long tree[1<<19],lazy[1<<19];
int cnt=0;
long long search(int index,int lb,int rb,int lq,int rq)
{
	if(rb==rq&&lb==lq)
		return tree[index];
	if(lazy[index]!=0)
	{
		tree[index<<1]+=lazy[index];
		lazy[index<<1]+=lazy[index];
		tree[index<<1|1]+=lazy[index];
		lazy[index<<1|1]+=lazy[index];
		lazy[index]=0;
	}
	int mid=(lb+rb)>>1;
	if(rq<=mid)
		return search(index<<1,lb,mid,lq,rq);
	else if(lq>mid)
		return search(index<<1|1,mid+1,rb,lq,rq);
	else
		return max(search(index<<1,lb,mid,lq,mid),search(index<<1|1,mid+1,rb,mid+1,rq));
}
void update(int index,int lb,int rb,int lq,int rq,long long value)
{
	if(lb==lq&&rb==rq)
	{
		tree[index]+=value;
		lazy[index]+=value;
		return ;
	}
	if(lazy[index]!=0)
	{
		tree[index<<1]+=lazy[index];
		lazy[index<<1]+=lazy[index];
		tree[index<<1|1]+=lazy[index];
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
		update(index<<1,lb,mid,lq,mid,value);
		update(index<<1|1,mid+1,rb,mid+1,rq,value);
	}
	tree[index]=max(tree[index<<1],tree[index<<1|1]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d%d%d",&arr[i].left,&arr[i].right,&arr[i].value);
	sort(arr,arr+m);
	for(int i=1;i<=n;i++)
	{
		update(1,0,n,i,i,search(1,0,n,0,i-1));
		while(i==arr[cnt].right&&cnt<m)
		{
			update(1,0,n,arr[cnt].left,arr[cnt].right,(long long)arr[cnt].value);
			cnt++;
		}
	}
	printf("%lld",search(1,0,n,0,n));
}