#include <bits/stdc++.h>
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
typedef long long ll;
const int N=200005;
int n,a[N],b[N];
using namespace std;

inline int read()
{
	char c;int x;
	while (c=getchar(),c<'0' || c>'9');x=c^'0';
	while (c=getchar(),c>='0' && c<='9') x=(x<<1)+(x<<3)+(c^'0');
	return x;
}
void write(int x)
{
	if (x==0) return;
	write(x/10);
	putchar((x%10)+'0');
}

int main()
{
	#ifdef Kay
		freopen ("code.in","r",stdin);
		freopen ("code.out","w",stdout);
	#endif
	scanf ("%d",&n);
	int i,j,k;
	for (i=1;i<=n;i++) a[i]=read();
	for (i=1,j=n,k=1;k<=n;k++)
	if (k&1) b[i++]=a[n-k+1];
	else b[j--]=a[n-k+1];
	for (i=1;i<=n;i++) printf ("%d ",b[i]);
	return 0;
}
