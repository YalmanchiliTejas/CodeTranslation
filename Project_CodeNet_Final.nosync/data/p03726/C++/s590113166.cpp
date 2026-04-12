#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
using namespace std;
typedef long long LL;
const int N=2e5;
int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
int head[N],nxt[N],to[N];
inline bool dfs(int k,int fa) {
	bool match=false;
	for (int i=head[k];i;i=nxt[i])
		if (to[i]!=fa) {
			if (dfs(to[i],k))
				if (match) { puts("First"); exit(0); }
				else match=true;
		}
	return !match;
}
int main()
{
	int n=gi(),i,a,b,tot=0;
	for (i=1;i<n;i++) {
		a=gi(),b=gi();
		to[++tot]=b,nxt[tot]=head[a],head[a]=tot;
		to[++tot]=a,nxt[tot]=head[b],head[b]=tot;
	}
	puts(dfs(1,0)?"First":"Second");
	return 0;
}
