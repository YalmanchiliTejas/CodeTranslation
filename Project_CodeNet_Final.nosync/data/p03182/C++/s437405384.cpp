#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int left,right,value;
	bool operator < (const struct node & t)const
	{
		return right<t.right;
	}
}EDGE,*PEDGE;
long long lazy[1<<19];
EDGE arr[1<<18];
long long tree[1<<19];
long long search(int index,int lb,int rb,int lq,int rq)
{
	if(lb==rb||lb==lq&&rb==rq)
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
	if(rq<=mid)
		update(index<<1,lb,mid,lq,rq,value);
	else if(lq>mid)
		update(index<<1|1,mid+1,rb,lq,rq,value);
	else
	{
		update(index<<1|1,mid+1,rb,mid+1,rq,value);
		update(index<<1,lb,mid,lq,mid,value);
	}		
	tree[index]=max(tree[index<<1],tree[index<<1|1]);
}
int main()
{
	int i,n,m;
	int cnt=0;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&arr[i].left,&arr[i].right,&arr[i].value);
	}
	sort(arr,arr+m);
	for(i=1;i<=n;i++)
	{
		update(1,0,n,i,i,search(1,0,n,0,i-1));
		while(i==arr[cnt].right&&cnt<m)
		{
			update(1,0,n,arr[cnt].left,arr[cnt].right,arr[cnt].value);
			cnt++;
		}
	}
	printf("%lld",search(1,0,n,0,n));
	return 0;
}