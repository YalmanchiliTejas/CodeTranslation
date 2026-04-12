#include<bits/stdc++.h>
#define LL long long
#define Max 100005
#define Mod 1e9+7
const LL mod=1e9+7;
const LL inf=0x3f3f3f3f;
using namespace std;
int main()
{
	LL n,x;
	LL siz[52],eat[52];
	siz[0]=eat[0]=1;
	scanf("%lld%lld",&n,&x);
	LL ans=0;
	for(int i=1;i<=n;i++)
	{
		siz[i]=siz[i-1]*2+3;
		eat[i]=eat[i-1]*2+1;
	}
	for(int i=n;i>=0;i--)
	{
		 if(x==0)
			break;
		if(x==siz[i])
		{
			ans+=eat[i];
			break;
		}
		if(x==1)
            break;
		if(x<=(siz[i-1]+1))
		{
			x--;
		}
		else
		{
          ans+=(eat[i-1]+1);
			x-=(siz[i-1]+2);
		}
	}
	printf("%lld\n",ans);
    return 0;
}