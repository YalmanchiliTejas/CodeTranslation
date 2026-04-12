#include<map>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define pb push_back
using namespace std;
const int P=139;
const int mod=998244353;
const int maxn=1e6+5;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int minn=0xc0c0c0c0;
ll k,m,n,x,ans,f[maxn],pre[maxn];
int main()
{
    scanf("%lld%lld%lld",&n,&x,&m);
    for(int i=0;i<m;i++)
    	f[i]=-1;
    int a=0;
    ans=0;
    while(n--)
    {
    	f[x]=a++;
    	pre[x]=ans;
    	ans+=x;
    	x=x*x%m;
    	if(f[x]>=0)
    	{
    		int b=a-f[x];
    		ans+=(ans-pre[x])*(n/b);
    		n%=b;
		}
	}
	printf("%lld\n",ans);
    return 0;
}