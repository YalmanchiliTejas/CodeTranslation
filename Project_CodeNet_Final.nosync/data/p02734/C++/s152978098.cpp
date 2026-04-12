#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 3e3 + 5;
const int MAXS = 3e3 + 5;
const int mod = 998244353;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

int a[MAXN];
int f[MAXN][MAXS];

int main(void)
{
	int n,s;
	scanf("%d%d",&n,&s);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	f[0][0]=1;
	int ans=0;
	for(int i=1; i<=n; ++i)
	{
		f[i][0]=1;
		for(int j=0; j<=s; ++j)
		{
			add_mod(f[i][j], f[i-1][j]);
			if(j>=a[i]) add_mod(f[i][j], f[i-1][j-a[i]]);
		}
		add_mod(ans, f[i][s]);
	}
	printf("%d",ans);
	return 0;
}