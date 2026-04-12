#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 5e2 + 5;

struct Node
{
	int x,y;
};

int s[MAXN],t[MAXN];
ull u[MAXN],v[MAXN];

ull ans[MAXN][MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&s[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&t[i]);
	for(int i=1; i<=n; ++i) scanf("%llu",&u[i]);
	for(int i=1; i<=n; ++i) scanf("%llu",&v[i]);
	
	try
	{
		for(int k=0; k<64; ++k)
		{
			static int p[MAXN],q[MAXN];
			for(int i=1; i<=n; ++i)
				p[i] = (u[i]>>k)&1,
				q[i] = (v[i]>>k)&1;
			
			static int a[MAXN][MAXN];
			static bool must[MAXN][MAXN];
			static bool delr[MAXN], delc[MAXN];
			static queue<Node> que;
			
			memset(must,0,sizeof(must));
			memset(delr,0,sizeof(delr));
			memset(delc,0,sizeof(delc));
			
			for(int i=1; i<=n; ++i)
			{
				if(s[i] == p[i]) continue;
				for(int j=1; j<=n; ++j)
				{
					if(must[i][j] && a[i][j]!=p[i]) throw 114514;
					a[i][j]=p[i]; must[i][j]=1;
					que.push((Node){i,j});
				}
				delr[i]=1;
			}
			for(int j=1; j<=n; ++j)
			{
				if(t[j] == q[j]) continue;
				for(int i=1; i<=n; ++i)
				{
					if(must[i][j] && a[i][j]!=q[j]) throw 114514;
					a[i][j]=q[j]; must[i][j]=1;
					que.push((Node){i,j});
				}
				delc[j]=1;
			}
			
			while(!que.empty())
			{
				int x=que.front().x, y=que.front().y;
				que.pop();
				
				if(!delr[x])
				{	
					if(!must[x][y])
					{
						a[x][y] = p[x];
						must[x][y]=1;
					}
					if(p[x] == a[x][y])
					{
						for(int j=1; j<=n; ++j)
							que.push((Node){x,j});
						delr[x]=1;
					}
				}
				if(!delc[y])
				{
					if(!must[x][y])
					{
						a[x][y] = q[y];
						must[x][y]=1;
					}
					if(q[y] == a[x][y])
					{
						for(int i=1; i<=n; ++i)
							que.push((Node){i,y});
						delc[y]=1;
					}
				}
			}
			
			int r=0,c=0;
			for(int i=1; i<=n; ++i)
				if(!delr[i]) ++r;
			for(int i=1; i<=n; ++i)
				if(!delc[i]) ++c;
			
			if(((bool)r) ^ ((bool)c)) throw 114514;
			if(r==1)
			{
				for(int i=1; i<=n; ++i)
					for(int j=1; j<=n; ++j)
					{
						if(!must[i][j])
							a[i][j] = q[j];
					}
			}
			if(c==1)
			{
				for(int i=1; i<=n; ++i)
					for(int j=1; j<=n; ++j)
					{
						if(!must[i][j])
							a[i][j] = p[i];
					}
			}
			if(r>1 && c>1)
			{
				for(int i=1,tmp=0; i<=n; ++i) if(!delr[i])
				{
					for(int j=1,now=tmp; j<=n; ++j) if(!delc[j])
					{
						a[i][j] = now;
						now^=1;
					}
					tmp^=1;
				}
			}
			
			for(int i=1; i<=n; ++i)
				for(int j=1; j<=n; ++j)
					ans[i][j] |= ((ull)a[i][j]<<k);
		}
	}
	catch(...)
	{
		printf("-1");
		return 0;
	}
	
	for(int i=1; i<=n; ++i,putchar('\n'))
		for(int j=1; j<=n; ++j) printf("%llu ",ans[i][j]);
	return 0;
}