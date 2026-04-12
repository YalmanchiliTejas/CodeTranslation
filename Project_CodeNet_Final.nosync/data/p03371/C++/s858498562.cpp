#include <bits/stdc++.h>
#define ri register
#define int long long
using namespace std; const int N=500010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int a,b,c,x,y;
signed main()
{
    a=read(), b=read(), c=read(), x=read(), y=read();
    if(2*c>a+b)
    {
        printf("%lld\n",x*a+y*b);
    }
    else
    {
        int qwq=min(x,y)*2*c;
        int g=min(x,y);
        x-=g, y-=g;
        if(x)
        {
            printf("%lld\n",qwq+x*min(a,c*2));
        }
        else{
            printf("%lld\n",qwq+y*min(b,c*2));
        }
    }
    return 0;
}