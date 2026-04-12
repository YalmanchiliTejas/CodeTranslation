#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<map>
#include<cmath>
#include<set>
#include<stack>
#define ll long long
#define pb push_back
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)>(y)?(y):(x))
#define cls(name,x) memset(name,x,sizeof(name))
using namespace std;
const int inf=1e9+10;
const int maxn=1e6+10;
const int maxm=20;
const int mod=1e9+7;
const double pi=acos(-1.0);
int n;
int ans[maxn*2];
int main()
{
    //freopen("in.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        int st=maxn-1,ed=maxn;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
                scanf("%d",&ans[ed++]);
            else
                scanf("%d",&ans[st--]);
        }
        if(n%2==0)
        for(int i=st+1;i<ed;i++)
            printf("%d%s",ans[i],i==ed-1?"\n":" ");
        else
            for(int i=ed-1;i>st;i--)
            printf("%d%s",ans[i],i==st+1?"\n":" ");
    }
    return 0;
}
