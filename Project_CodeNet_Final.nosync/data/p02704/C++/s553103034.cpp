#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=505;

int n;
int tx[MAXN],ty[MAXN];//0:and 1:or
ull ax[MAXN],ay[MAXN];
int bx[MAXN],by[MAXN],t[MAXN][MAXN],cnt[MAXN];
ull res[MAXN][MAXN];

int main()
{
	readint(n);
	for(int i=1;i<=n;++i)cin>>tx[i];
	for(int i=1;i<=n;++i)cin>>ty[i];
	for(int i=1;i<=n;++i)cin>>ax[i];
	for(int i=1;i<=n;++i)cin>>ay[i];
	for(int k=0;k<64;++k)
	{
		int hx[4]={0,0,0,0},hy[4]={0,0,0,0};
		for(int i=1;i<=n;++i)
		{
			bx[i]=(ax[i]>>k)&1,by[i]=(ay[i]>>k)&1;
			++hx[tx[i]*2+bx[i]];
			++hy[ty[i]*2+by[i]];
		}
		if(hx[1] && hy[2])return 0*printf("-1\n");
		if(hx[2] && hy[1])return 0*printf("-1\n");
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)t[i][j]=bx[i];
			cnt[i]=n;
		}
		for(int j=1;j<=n;++j)
			if(ty[j]!=by[j])
				for(int i=1;i<=n;++i)
					if(t[i][j]!=by[j])--cnt[i],t[i][j]=by[j];
		for(int j=1;j<=n;++j)
			if(ty[j]==by[j])
			{
				bool flag=0;
				for(int i=1;i<=n;++i)
					if(t[i][j]==by[j]){flag=1;break;}
				if(flag)continue;
				for(int i=1;i<=n;++i)
					if(bx[i]==tx[i] && cnt[i]>=2)
					{
						--cnt[i],t[i][j]=by[j];
						break;
					}
			}
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				res[i][j]|=((ull)t[i][j]<<k);
	}
	for(int i=1;i<=n;++i)
	{
		ull u=res[i][1];
		for(int j=2;j<=n;++j)
			if(tx[i]==0)u&=res[i][j];
			else u|=res[i][j];
		if(u!=ax[i])return 0*printf("-1\n");
	}
	for(int j=1;j<=n;++j)
	{
		ull u=res[1][j];
		for(int i=2;i<=n;++i)
			if(ty[j]==0)u&=res[i][j];
			else u|=res[i][j];
		if(u!=ay[j])return 0*printf("-1\n");
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}