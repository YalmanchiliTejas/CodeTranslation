#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int p=1000000007;

int edge[500000],nxt[500000],dist[500000],first[300000],deg[300000];
int g[300000],h1[300000],h2[300000],x[300000],y[300000],z[300000];
long long f1[300000],f2[300000];
bool b[300000];
int i,j,m,n,s,u,v,w,head,tail,sum_edge;
long long t;

inline void addedge(int x,int y,int z)
{
	sum_edge++,edge[sum_edge]=y,nxt[sum_edge]=first[x],dist[sum_edge]=z,first[x]=sum_edge;
	return;
}

struct heapnode
{
	long long num;
	int ord;
	
	inline bool operator < (const heapnode t) const
	{
		return num<t.num;
	}
};

heapnode heap[300000];
int toheap[300000];
int sum_heap;

inline void heap_swap(int node1,int node2)
{
	swap(toheap[heap[node1].ord],toheap[heap[node2].ord]);
	swap(heap[node1],heap[node2]);
	return;
}

inline void heap_up(int node)
{
	while ((node>1) && (heap[node]<heap[node>>1]))
	{
		heap_swap(node,node>>1);
		node=node>>1;
	}
	return;
}

inline void heap_down(int node)
{
	for (;;)
	{
		bool left=false,right=false;
		if (((node<<1)<=sum_heap) && (heap[node<<1]<heap[node]))
			left=true;
		if (((node<<1|1)<=sum_heap) && (heap[node<<1|1]<heap[node]))
			right=true;
		if ((left) && (right))
			if (heap[node<<1]<heap[node<<1|1])
				right=false;
			else
				left=false;
		if ((! left) && (! right))
			return;
		if (left)
		{
			heap_swap(node,node<<1);
			node=node<<1;
		}
		if (right)
		{
			heap_swap(node,node<<1|1);
			node=node<<1|1;
		}
	}
}

inline void heap_in(long long num,int ord)
{
	sum_heap++;
	heap[sum_heap].num=num;
	heap[sum_heap].ord=ord;
	toheap[heap[sum_heap].ord]=sum_heap;
	heap_up(sum_heap);
	return;
}

inline void heap_pushtop()
{
	heap_swap(1,sum_heap);
	sum_heap--;
	heap_down(1);
	return;
}

inline void heap_insert(long long num,int ord)
{
	heap[toheap[ord]].num=num;
	heap_up(toheap[ord]);
	heap_down(toheap[ord]);
	return;
}

inline void dijkstra(int x,long long *f)
{
	memset(b,false,sizeof(b));
	f[x]=0;
	for (i=1;i<=n;i++)
		heap_in(f[i],i);
	for (i=1;i<=n;i++)
	{
		w=heap[1].ord;
		heap_pushtop();
		b[w]=true;
		for (j=first[w];j!=0;j=nxt[j])
			if ((! b[edge[j]]) && (f[w]+dist[j]<f[edge[j]]))
			{
				f[edge[j]]=f[w]+dist[j];
				heap_insert(f[edge[j]],edge[j]);
			}
	}
	return;
}

inline void topologysort(int x,int y,int *h)
{
	for (i=1;i<=n;i++)
		for (j=first[i];j!=0;j=nxt[j])
			if ((j&1)==y)
				deg[edge[j]]++;
	tail=0;
	for (i=1;i<=n;i++)
		if (! deg[i])
			tail++,g[tail]=i;
	h[x]=1;
	for (head=1;head<=tail;head++)
		for (i=first[g[head]];i!=0;i=nxt[i])
			if ((i&1)==y)
			{
				h[edge[i]]=(h[edge[i]]+h[g[head]])%p;
				deg[edge[i]]--;
				if (! deg[edge[i]])
					tail++,g[tail]=edge[i];
			}
	return;
}

int main()
{
	scanf("%d%d",&n,&m);
	scanf("%d%d",&u,&v);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		addedge(x[i],y[i],z[i]),addedge(y[i],x[i],z[i]);
	}
	memset(f1,12,sizeof(f1));
	dijkstra(u,f1);
	memset(f2,12,sizeof(f2));
	dijkstra(v,f2);
	t=f2[u];
	memset(first,0,sizeof(first));
	sum_edge=0;
	for (i=1;i<=m;i++)
	{
		if (f1[x[i]]>f1[y[i]])
			swap(x[i],y[i]);
		if (f1[x[i]]+f2[y[i]]+z[i]==t)
			addedge(x[i],y[i],z[i]),addedge(y[i],x[i],z[i]);
	}
	topologysort(u,1,h1);
	topologysort(v,0,h2);
	for (i=1;i<=n;i++)
		if ((2*f1[i]==t) && (2*f2[i]==t))
			s=(s+1LL*h1[i]%p*h2[i]%p*h1[i]%p*h2[i]%p)%p;
	for (i=1;i<=m;i++)
		if ((2*f1[x[i]]<t) && (2*f2[y[i]]<t) && (f1[x[i]]+f2[y[i]]+z[i]==t))
			s=(s+1LL*h1[x[i]]%p*h2[y[i]]%p*h1[x[i]]%p*h2[y[i]]%p)%p;
	printf("%d",(1LL*h1[v]*h2[u]%p-s+p)%p);
	return 0;
}