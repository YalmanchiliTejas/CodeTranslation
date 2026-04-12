#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define s second
#define f first
#define mt make_tuple
#define foreach(it, a) for(__typeof(a.begin()) it=a.begin(); it!=a.end(); it++)
#define forn(i, a) for(int i=0; i<a; i++)
#define INF 1e9
#define all(x) x.begin(), x.end()
#define MOD 1e9+7 

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<pi,int> pii;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef unsigned int uint;

int N, par[100005], ranks[100005], a, b, cnt=0;
ll res=0;

struct town
{
	int x, y, id;
	town(int a, int b, int c)
	{
		x=a;
		y=b;
		id=c;
	}
	town(){}
}T[100005], rT[100005];

struct Node
{
	ll cost;
	int x;
	int y;
	Node(ll a, int b, int c)
	{
		cost=a;
		x=b;
		y=c;
	}
	Node(){}
}fin[300005];

inline bool cmp(const Node&a, const Node&b)
{
	return a.cost<b.cost;
}
inline bool cmpx(const town&a, const town&b)
{
	return a.x<b.x;
}
inline bool cmpy(const town&a, const town&b)
{
	return a.y<b.y;
}
void init()
{
	for(int i=0; i<N; i++)
		par[i]=i, ranks[i]=0;
}

inline int find(int x)
{
	return par[x]==x?x:par[x]=find(par[x]);
}

inline bool unite(int x, int y)
{
	x=find(x), y=find(y);
	if(x==y)
		return  false;
	if(ranks[x]<ranks[y])
		par[x]=y;
	else
	{
		par[y]=x;
		if(ranks[x]==ranks[y])
			ranks[x]++;
	}
	return true;
}

int main() 
{
	scanf("%d", &N);
	init();
	for(int i=0; i<N; i++)
	{
		scanf("%d %d", &a, &b);
		T[i]=town(a, b, i);
		rT[i]=T[i];
	}
	sort(T, T+N, cmpx);	
	sort(rT, rT+N, cmpy);	
	
	for(int i=0; i<N-1; i++)
	{
		fin[cnt++]=Node(min(abs(T[i].x-T[i+1].x), abs(T[i].y-T[i+1].y)), T[i].id, T[i+1].id);
		fin[cnt++]=Node(min(abs(rT[i].x-rT[i+1].x), abs(rT[i].y-rT[i+1].y)), rT[i].id, rT[i+1].id);
	}
	sort(fin, fin+cnt, cmp);
/*	for(int i=0; i<cnt; i++)
	{
		cout<<fin[i].cost<<" "<<fin[i].x<<" "<<fin[i].y<<endl;
	}*/
	for(int i=0; i<cnt; i++)
	{
		res+=unite(fin[i].x, fin[i].y)*fin[i].cost;
	}
	cout<<res<<endl;
	return 0;
}