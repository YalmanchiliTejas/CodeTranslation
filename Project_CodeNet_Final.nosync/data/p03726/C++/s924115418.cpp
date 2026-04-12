#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
const int maxn=100000+10;
int h[maxn],go[maxn*2],nxt[maxn*2];
int i,j,k,l,t,n,m,tot;
void add(int x,int y){
    go[++tot]=y;
    nxt[tot]=h[x];
    h[x]=tot;
}
int perfect(int x,int y){
    int t=h[x];
    int p=0;
    while (t){
        if (go[t]!=y) p+=perfect(go[t],x);
        t=nxt[t];
    }
    if (p>=2) return p;
    else return p^1;
}
int main(){
    scanf("%d",&n);
    fo(i,1,n-1){
        scanf("%d%d",&j,&k);
        add(j,k);add(k,j);
    }
    if (perfect(1,0)==0) printf("Second\n");
    else printf("First\n");
}