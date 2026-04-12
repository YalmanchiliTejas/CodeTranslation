#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define FORD(x,y,z) for(int x=y;x>=z;x--)
#define MSET(x,y) memset(x,y,sizeof(x))
#define FOR(x,y) for(__typeof(y.begin()) x=y.begin();x!=y.end();x++)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define M 300005
#define L (cur*2)
#define R (L+1)
void RI(){}
template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
using namespace std;
typedef long long LL;
int n,q;
int mnr[M*4], sum[M*4], posl[M*4];
char buf[M];

void up(int cur,int ll,int rr)
{
	sum[cur] = sum[L] + sum[R];
	posl[cur] = min(posl[L], posl[R]);
	mnr[cur] = min(mnr[R], sum[R]+mnr[L]);
}
void init(int cur,int ll,int rr)
{
	if(ll==rr)
	{
		if(buf[ll]=='(')
		{
			sum[cur] = mnr[cur] = -1;
			posl[cur] = M;
		}
		else
		{
			sum[cur] = mnr[cur] = 1;
			posl[cur] = ll;
		}
		return;
	}

	int mid = (ll+rr)/2;
	init(L,ll,mid);
	init(R,mid+1,rr);
	up(cur,ll,rr);
}
void upd(int cur,int ll,int rr,int x,int v)
{
	if(ll==rr)
	{
		sum[cur] = mnr[cur] = v;
		
		if(v==-1) posl[cur]=M;
		else posl[cur]=ll;
		return;
	}

	int mid = (ll+rr)/2;
	if(x<=mid) upd(L,ll,mid,x,v);
	else upd(R,mid+1,rr,x,v);
	up(cur,ll,rr);
}
int ask(int cur,int ll,int rr,int s)
{
	if(ll==rr)
	{
		if(s!=mnr[cur]) return -1;
		return ll;
	}

	int mid = (ll+rr)/2;
	
	if(mnr[R] > s)
	{
		int re = ask(L,ll,mid,s-sum[R]);
		if(re!=-1) return re;
		return mid+1;
	}
	return ask(R,mid+1,rr,s);
}

int main()
{
	int x;
	RI(n,q);
	scanf("%s", buf+1);
	init(1,1,n);

	while(q--)
	{
		scanf("%d",&x);
		if(buf[x]=='(')
		{
			buf[x] = ')';
			upd(1,1,n,x,1);
			
			x = posl[1];
			buf[x] = '(';
			upd(1,1,n,x,-1);
			printf("%d\n",x);
		}
		else
		{
			buf[x] = '(';
			upd(1,1,n,x,-1);

			x = ask(1,1,n,-1);
			buf[x] = ')';
			upd(1,1,n,x,1);
			printf("%d\n", x);
		}
	}
	return 0;
}