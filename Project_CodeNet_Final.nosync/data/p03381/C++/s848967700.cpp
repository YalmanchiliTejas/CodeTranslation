//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <limits>
#include <map>
#include <vector>
#include <queue> 
#define LL long long
#define ft first
#define sd second
#define mp(x,y) make_pair(x,y)
//#define int LL
#define db double
using namespace std;
const int N   = 2e5+233;
//const int mod = ;
const int INF =numeric_limits<int >::max();
#define For(n) for (int i=1;i<=n;++i)
#define rep(i,x,y) for (int i=x;i<=y;++i)
void read(int &x)
{
	x=0;
	char ch=getchar();
	int f=1;
	while (!isdigit(ch)) (ch=='-'?f=-1:0),ch=getchar();
	while ( isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	x*=f;
}

int n,a[N],pos[N],b[N],k;

signed main()
{
	read(n);
	rep(i,1,n) read(a[i]),b[i]=a[i];
	sort(b+1,b+1+n);
	k=n/2;
	if (b[k]==b[k+1])
	{
		rep(i,1,n) printf("%d\n",b[k]);
		return 0;
	}
	rep(i,1,n) if (a[i]<=b[k]) printf("%d\n",b[k+1]);else printf("%d\n",b[k]);
	return 0;
}
