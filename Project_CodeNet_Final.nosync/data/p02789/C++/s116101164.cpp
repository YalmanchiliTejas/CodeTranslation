#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#include<ctime>

using namespace std;

template <typename T>

inline T read()
{
	T x=0,f=1;char c=getchar();
	while(!isdigit(c))
	{if(c=='-') f=-f;c=getchar();}
	while(isdigit(c))
	{x=(x<<3)+(x<<1)+(c-48);c=getchar();}
	return x*f;
}

#define lint long long int
#define ulint unsigned lint

const int inf=1e9+1e7;

int n,m;

int main(void)
{

	// freopen("testdata.in","r",stdin);
	// freopen("testdata.out","w",stdout);

	scanf("%d%d",&n,&m);

	if(n==m) puts("Yes");
	else puts("No");

	return 0;

}