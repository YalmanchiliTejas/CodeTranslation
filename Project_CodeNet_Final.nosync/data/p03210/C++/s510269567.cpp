#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORL(i,x) for(int i=head[x];i;i=nxt[i])
#define clr(x,y) memset(x,y,sizeof(x))
#define in(a) a=read()
#define out(a) printf("%d\n",a)
inline ll read(){
	char c=getchar();ll f=1,x=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return x*f;
}
#define mod 1000000007
#define maxn 100010
#define inf (1<<30)
char s[maxn];
int main(){
	int n;
	in(n);
	if(n==3||n==5||n==7)puts("YES");
	 else puts("NO");
}
//5*5*3
