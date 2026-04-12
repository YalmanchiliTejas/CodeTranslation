#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<sstream>
#include<vector>
#define inf 2147483647
#define rep(i,a,b) for(int i=a;i<b;i++)
#define  rr read()
#define ll long long
#define repb(i,a,b) for(int i=a;i<=b;i++)
#define CloseIo   ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
int read()
{
    char ch = getchar();
	int x = 0, f = 1;
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while('0' <= ch && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
int main()
{
int n=rr;
int a[105]={0};
int count=0,maxx=0;;
rep(i,0,n)
{
	a[i]=rr;
	if(a[i]>=maxx)
	{
		count++;
		maxx=a[i];
	}
}
printf("%d\n",count);
}

