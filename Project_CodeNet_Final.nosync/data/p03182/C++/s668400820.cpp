#include <bits/stdc++.h>
using namespace std;
typedef struct line
{
        int lp,rp,value;
        bool operator < (const struct line & t) const
        {
                return rp<t.rp;
        }
}LINE,*PLINE;
LINE arr[200001];
int n,m;
long long lazy[1<<19],linetree[1<<19];
long long query(int index,int lb,int rb,int lq,int rq)
{
        if(lb==lq&&rb==rq)
        {
                return linetree[index];
        }
        if(lazy[index])
        {
                linetree[index<<1]+=lazy[index];
                linetree[index<<1|1]+=lazy[index];
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
        {
                return max(query(index<<1,lb,mid,lq,mid),query(index<<1|1,mid+1,rb,mid+1,rq));
        }
}
void update(int index,int lb,int rb,int lq,int rq,long long value)
{
        if(lb==lq&&rb==rq)
        {
                linetree[index]+=value;
                lazy[index]+=value;
                return ;
        }
        if(lazy[index])
        {
                linetree[index<<1]+=lazy[index];
                linetree[index<<1|1]+=lazy[index];
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
                update(index<<1,lb,mid,lq,mid,value);
                update(index<<1|1,mid+1,rb,mid+1,rq,value);
        }
        linetree[index]=max(linetree[index<<1],linetree[index<<1|1]);
}
int main()
{
        int i,cnt=1;
        scanf("%d %d",&n,&m);
        for(i=1;i<=m;i++)
        {
                scanf("%d %d %d",&arr[i].lp,&arr[i].rp,&arr[i].value);
        }
        sort(arr+1,arr+m+1);
        for(i=1;i<=n;i++)
        {
                update(1,0,n,i,i,query(1,0,n,0,i-1));
                while(arr[cnt].rp==i)
                {
                        update(1,0,n,arr[cnt].lp,arr[cnt].rp,arr[cnt].value);
                        cnt++;
                }
        }
        printf("%lld",linetree[1]);
        return 0;
}
