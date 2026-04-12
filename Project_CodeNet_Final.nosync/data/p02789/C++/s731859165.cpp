//QWsin
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define out(i,u) for(int i=first[u];i!=-1;i=nxt[i])
#define repvc(i,vc) for(int i=0,Sz=vc.size();i<Sz;++i)
using namespace std;
inline int read()
{
	char ch=getchar();int ret=0,f=1;
	while(ch<'0' || ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	for(;ch>='0' && ch<='9';ch=getchar()) ret=ret*10+ch-'0';
	return ret*f;
}

typedef long long ll;
const int INF=1<<30;

int main()
{
//	freopen("std.in","r",stdin);
	int n,m;cin>>n>>m;
	puts(n==m?"Yes":"No");
	return 0;
}
