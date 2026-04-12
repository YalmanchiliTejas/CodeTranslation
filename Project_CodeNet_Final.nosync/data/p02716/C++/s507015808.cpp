#include <bits/stdc++.h>
#define int long long
using std::max;
const int MAXN=200005;
int n,i,a[MAXN],f[MAXN][3];
inline void read(int &x)
{
	short negative=1;
    x=0;
    char c=getchar();
    while(c<'0' || c>'9')
    {
    	if(c=='-')
			negative=-1;
		c=getchar();
	}
    while(c>='0' && c<='9')
        x=(x<<3)+(x<<1)+(c^48),c=getchar();
    x*=negative;
}
inline void print(int x)
{
    if (x<0)
        putchar('-'),x=-x;
    if (x>9)
        print(x/10);
    putchar(x%10+'0');
}
signed main(void)
{
	read(n);
	for (i=1;i<=n;i++)
		read(a[i]);
	if (!(n%2))
	{
		f[1][0]=a[1];
		for (i=2;i<=n;i++)
			if (i%2)
				f[i][0]=f[i-2][0]+a[i];
			else
			{
				if (i>=3)
					f[i][1]=max(f[i-2][1],f[i-3][0])+a[i];
				else
					f[i][1]=f[i-2][1]+a[i];
			}
		return print(max(f[n-1][0],f[n][1])),0;
	}
	f[1][0]=a[1];
	for (i=2;i<=n;i++)
		if (i%2)
		{
			f[i][0]=f[i-2][0]+a[i];
			if (i>=4)
				f[i][2]=max(f[i-2][2],max(f[i-3][1],f[i-4][0]))+a[i];
			else
			{
				if (i>=3)
					f[i][2]=max(f[i-2][2],f[i-3][1])+a[i];
				else
					f[i][2]=f[i-2][2]+a[i];
			}
		}
		else
		{
			if (i>=3)
				f[i][1]=max(f[i-2][1],f[i-3][0])+a[i]; 
			else
				f[i][1]=f[i-2][1]+a[i];
		}
	print(max(f[n][2],max(f[n-1][1],f[n-2][0])));
	return 0;
}