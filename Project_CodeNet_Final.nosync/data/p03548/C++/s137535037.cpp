
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#define ll long long
#define out(a) printf("%d",a)
using namespace std;
int n;
char c1,c2,c3;
int a,b,c;
int read()
{
	int s=0,t=1; char c;
	while (c<'0'||c>'9') {if (c=='-') t=-1; c=getchar();}
	while (c>='0'&&c<='9') {s=s*10+c-'0'; c=getchar();}
	return s*t;
}
int main()
{
  a=read(); b=read(); c=read();
  a-=c;
  out(a/(b+c));
}