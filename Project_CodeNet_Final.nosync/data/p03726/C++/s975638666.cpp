/*Program from Luvwgyx*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
struct node{int to,nxt;}e[maxn<<1];
int tot,head[maxn];
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
void write(int x){print(x);puts("");}
void add(int u,int v){e[++tot].to=v;e[tot].nxt=head[u];head[u]=tot;}
int dfs(int x,int fa){
    int ret=0;
    for(int i=head[x],v=e[i].to;i;i=e[i].nxt,v=e[i].to)
        if(v!=fa)ret+=dfs(v,x);
    return ret>=2?ret:ret^1;
}
int main(){
    int n=read();
    for(int i=1;i<n;i++){int u=read(),v=read();add(u,v);add(v,u);}
    puts(dfs(1,0)?"First":"Second");
    return 0;
}
