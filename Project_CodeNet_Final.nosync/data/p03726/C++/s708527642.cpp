#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
const int N=100010;
int tt;
int head[N],to[N*2],nxt[N*2];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
inline int dfs(int x,int fa) {
    int ret=0;
    for(int i=head[x];i;i=nxt[i])
	if(to[i]!=fa) ret+=dfs(to[i],x);
    if(ret>1) puts("First"),exit(0);
    return !ret;
}
int main() {
    int n;
    cin>>n;
    for(int i=1;i<n;i++) {
	int x=gi(),y=gi();
	to[++tt]=y,nxt[tt]=head[x],head[x]=tt;
	to[++tt]=x,nxt[tt]=head[y],head[y]=tt;
    }
    puts(dfs(1,0)?"First":"Second");
    return 0;
}