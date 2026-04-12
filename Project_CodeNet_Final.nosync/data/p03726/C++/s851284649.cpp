#include <cstdio>
using namespace std;

const int maxn=1e5+5;

int n,tot;
int now[maxn],pre[maxn<<1],son[maxn<<1];

int read() {
    int x=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
    return x*f;
}

void add(int a,int b) {
    pre[++tot]=now[a];
    now[a]=tot,son[tot]=b;
}

int dfs(int fa,int u) {
    int res=0;
    for(int p=now[u],v=son[p];p;p=pre[p],v=son[p])
        if(v!=fa)res+=dfs(u,v);
    if(res>=2)return res;
    else return res^1;
}

int main() {
    n=read();
    for(int i=1;i<n;i++) {
        int a=read(),b=read();
        add(a,b),add(b,a);
    }
    if(dfs(0,1))puts("First");
    else puts("Second");
    return 0;
}
