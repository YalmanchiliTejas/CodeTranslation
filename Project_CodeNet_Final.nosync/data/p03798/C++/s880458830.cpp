//xtwakioi! xtwddYnoi(双重含义)!
#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std; const int N=200010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,f[N];
char s[N];
inline bool Check()
{
    for(ri int i=1;i<=n;i++)
    {
        int p,q;
        p=i-1, q=i+1;
        if(!p) p=n;
        if(q>n) q=1;
        if(f[i]==1)
        {
            if(s[i]=='o'&&f[p]!=f[q]) return 0;
            if(s[i]=='x'&&f[p]==f[q]) return 0;
        }
        else
        {
            if(s[i]=='o'&&f[p]==f[q]) return 0;
            if(s[i]=='x'&&f[p]!=f[q]) return 0;
        }
    }
    return 1;
}
signed main()
{
    scanf("%lld",&n);
    scanf("%s",s+1);
    for(ri int i=1;i<=2;i++)
    for(ri int j=1;j<=2;j++)
    {
        f[1]=i, f[2]=j;
        for(ri int k=2;k<n;k++)
        {
            if(f[k]==1)
            {
                if(s[k]=='o') f[k+1]=f[k-1];
                else f[k+1]=(f[k-1]==1?2:1);
            }
            else
            {
                if(s[k]=='x') f[k+1]=f[k-1];
                else f[k+1]=(f[k-1]==1?2:1);
            }
        }
        if(Check())
        {
            for(ri int k=1;k<=n;k++) printf("%c",f[k]==1?'S':'W');
            puts("");
            return 0;
        }
    }
    puts("-1");
    return 0;
}