#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<ctime>
#include<map>
#include<bitset>
#include<set>
#include<assert.h>
#include<chrono>
#include<random>
#define LL long long
#define mp(x,y) make_pair(x,y)
#define pll pair<long long,long long>
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline LL read()
{
	LL f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int stack[20];
template<typename T>inline void write(T x)
{
	if(x<0){putchar('-');x=-x;}
    if(!x){putchar('0');return;}
    int top=0;
    while(x)stack[++top]=x%10,x/=10;
    while(top)putchar(stack[top--]+'0');
}
template<typename T>inline void pr1(T x){write(x);putchar(' ');}
template<typename T>inline void pr2(T x){write(x);putchar('\n');}
template<typename T>inline void chkmin(T &x,T y){x=x<y?x:y;}
template<typename T>inline void chkmax(T &x,T y){x=x>y?x:y;}
const int mod=998244353;
const int MAXN=3005;
void ad(int &x,int y){x+=y;if(x>=mod)x-=mod;}
void dl(int &x,int y){x-=y;if(x<0)x+=mod;}
int n,S,a[MAXN],f[MAXN][MAXN];
int main()
{
	n=read();S=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		memcpy(f[i],f[i-1],sizeof(f[i]));
		for(int j=S-a[i];j>=1;j--)if(f[i-1][j])
		{
			if(j+a[i]!=S)ad(f[i][j+a[i]],f[i-1][j]);
			else
			{
				ad(ans,1LL*n*f[i-1][j]%mod);
				dl(ans,1LL*(i-1)*f[i-1][j]%mod);
			}
		}
		if(a[i]==S)ad(ans,1LL*i*(n-i+1)%mod);
		else if(a[i]<S)ad(f[i][a[i]],i);
	}pr2(ans);
	
	return 0;
}

