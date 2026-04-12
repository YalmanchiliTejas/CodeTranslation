#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<bitset>
#include<complex>
#include<cmath>
using namespace std;
template<typename __T>
inline void read(__T &x)
{
    x=0;
    int f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')	f=-1;c=getchar();}
    while(isdigit(c))	{x=x*10+c-'0';c=getchar();}
    x*=f;
}
int n,k;
int main()
{
	read(n);
	read(k);
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i<=k)	continue;
		int gg=max((n-n/i*i)-k+1,0);
		if(k==0)
			gg--;
		ans+=(n/i)*(i-k)+gg;
	}
	cout<<ans<<endl;
	return 0;
}