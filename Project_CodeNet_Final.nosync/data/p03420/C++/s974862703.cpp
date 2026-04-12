#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<vector>
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pa;
const int N=100010;
int n,k;
LL ans;
//vector<int>e[N];
int Write[20],WRI;
void judge(){freopen(".in","r",stdin);freopen(".out","w",stdout);}
int read(){int d=0,f=1; char c=getchar(); while (c<'0'||c>'9'){if (c=='-') f=-1; c=getchar();} while (c>='0'&&c<='9') d=d*10+c-48,c=getchar(); return d*f;}
void write(int x){if (!x){putchar('0'); return;}if (x<0) putchar('-'),x=-x;for (WRI=1;x;x/=10,WRI++) Write[WRI]=x%10;for (int i=WRI-1;i;i--) putchar((char)(Write[i]+48));}
int main()
{
	//judge();
	n=read(); k=read();
	for (int b=k+1;b<=n;b++)
	{
		//ans+=n/b*(n-k+1);
		ans+=n/b*(b-k);
		if (n%b>=k)
			if (k>0) ans+=n%b-k+1;
			else ans+=n%b-k;
		//ans+=(n-k-1)/b+1;
	}
	printf("%lld",ans);
	return 0;
}