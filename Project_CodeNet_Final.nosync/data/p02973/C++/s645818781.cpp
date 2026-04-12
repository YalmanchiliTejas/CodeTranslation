// This code Write By chtholly_micromaker(MicroMaker)
#include <cstdio>
#include <cctype>
#include <algorithm>
#define reg register
using namespace std;
const int MaxN=100001;
template <class t> inline void rd(t &s)
{
	s=0;
	reg char c=getchar();
	while(!isdigit(c))
		c=getchar();
	while(isdigit(c))
		s=(s<<3)+(s<<1)+(c^48),c=getchar();
	return;
}
int a[MaxN],f[MaxN],prayforkyoani[MaxN];
signed main(void)
{
	int n;
	reg int ans=1,chtholly=0;
	rd(n);
	for(int i=1;i<=n;++i)
		rd(a[i]);
    for(int i=1;i<=n;++i) 
    {
        f[i]=1;
        for(int j=chtholly;j;--j)
            if(a[i]<=a[prayforkyoani[j]]) 
            {
                f[i]=f[prayforkyoani[j]]+1;
                break;
            }
        chtholly=max(chtholly,f[i]);
        prayforkyoani[f[i]]=i;
        ans=max(ans,f[i]);
    }
    printf("%d",ans);
	return 0;
}