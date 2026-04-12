//Have a nice day:)
#include<bits/stdc++.h>
using namespace std;
#define LL long long

inline LL read();

const int N=50+2;
LL n;
LL cnt, a[N];

bool Minus()
{
    int id=0;
    for(int i=1; i<=n; ++i)
        if(a[i]>a[id]) id=i;
     
    if(id)
    {
        LL k=a[id]/n; a[id]%=n; cnt+=k;
        for(int j=1; j<=n; ++j) 
            if(j^id) a[j]+=k;
        return true;
    }

    return false;
}

void Work()
{
    n=read(); a[0]=n-1;
    for(int i=1; i<=n; ++i) a[i]=read();
    while(Minus());
    printf("%lld", cnt);
}

int main()
{
    #ifdef gc
    freopen("79c.in","r",stdin);
    freopen("79c.out","w",stdout);
    #endif

    Work();

    return 0;
}

inline LL read()
{
    char c; bool type=1;
    while((c=getchar())<'0' || c>'9')
        if(c=='-') type=0;
    LL ans=c^48;
    while((c=getchar())>='0' && c<='9')
        ans=(ans<<3)+(ans<<1)+(c^48);
    return type?ans:-ans;
}
