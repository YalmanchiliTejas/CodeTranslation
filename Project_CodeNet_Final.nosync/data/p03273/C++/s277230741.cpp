#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
const int maxn=2e5+7;
const ll modn=1e9+7;
const int inf=2e9+7;
const ll INF=1000000000000000000ll;
const double PI = acos(-1.0);
const double eps=1e-8;
inline int lowbit(int x){return x&-x;}
inline ll lowbit(ll x) {return x&-x;}
inline int CountOneBinary(ll num){int ans=0;while(num){if(num&1) ans+=1;num>>=1;}return ans;}
inline void read(int &x){char c;x=0;for(c=getchar();c>'9'||c<'0';c=getchar());for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';}
inline void read(ll &x){char c;x=0;for(c=getchar();c>'9'||c<'0';c=getchar());for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';}
inline ll qpow(ll x,ll y){ll ans=1;while(y){if(y&1) ans=ans*x%modn;x=x*x%modn;y>>=1;}return ans;}
inline double qpow(double x,ll y){double ans=1;while(y){if(y&1) ans=ans*x;x=x*x;y>>=1;}return ans;}
int h,w,vh[111],vw[111];
char s[111][111];
int main()
{
    while(scanf("%d%d",&h,&w)==2)
    {
        memset(vh,0,sizeof(vh));
        memset(vw,0,sizeof(vw));
        for(int i=1;i<=h;i++) scanf("%s",s[i]+1);
        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=w;j++)
            {
                if(s[i][j]=='#') vh[i]++,vw[j]++;
            }
        }
        for(int i=1;i<=h;i++)
        {
            if(!vh[i]) continue;
            for(int j=1;j<=w;j++)
            {
                if(vw[j]) putchar(s[i][j]);
            }
            putchar('\n');
        }
    }
}
