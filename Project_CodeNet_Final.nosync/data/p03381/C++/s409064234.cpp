#include <bits/stdc++.h>
using namespace std;
#define array_input int n;cin>>n;int a[n+1],i;for(i=1;i<=n;i++){cin>>a[i];}
#define array_output for(i=1;i<=n;i++){cout<<a[i]<<" ";}cout<<endl;
#define INF 2147483647
#define long_INF 18446744073709551615
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
const double pi=acos(-1);
const double eps=1e-6;

void read(int &x)
{
    x=0;
	char c=getchar();
    while(c<'0' || c>'9')c=getchar();
    while(c>='0' && c<='9')
	{
        x=x*10+c-'0';
        c=getchar();
    }
}

void write(int x)
{
    if(x==0)
	{
		putchar(48);
		return;
	}
    int len=0,dg[20];
    while(x>0)
	{
		dg[++len]=x%10;
		x/=10;
	}
    for(int i=len;i>=1;i--)
	{
		putchar(dg[i]+48);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	read(n);
	int a[n+1],i,t[n+1];
	for (i=1;i<=n;i++)
	{
		read(a[i]);
		t[i]=a[i];
	}
	sort(a+1,a+n+1);
	int maxv,minv;
	maxv=a[n/2];
	minv=a[n/2+1];
	for (i=1;i<=n;i++)
	{
		if (t[i]<=maxv)
		{
			cout<<a[n/2+1]<<endl;
		}
		else
		{
			cout<<a[n/2]<<endl;
		}
	}
	return 0;
}