#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
queue<int> q;
const ll inf=1ll<<60;
const int N=400010,mod=(int)1e9+7;
int eg[N][3];
int e[N],nex[N],head[N],c[N],ed=0;
ll d1[N],d2[N];
int ind[N],inq[N],f[N],g[N];
int n,m;
void upd(int &x,int y){x=(x+y)%mod;}
void adde(int x,int y,int z){e[++ed]=y;nex[ed]=head[x];head[x]=ed;c[ed]=z;}
void spfa(int S,int T,ll *d,int *f){
    int i,t,x,y,z;
    for(i=1;i<=n;i++) d[i]=inf,ind[i]=0;
    d[S]=0;q.push(S);inq[S]=1;
    while(!q.empty()){
        t=q.front();q.pop();inq[t]=0;
        for(i=head[t];i;i=nex[i]){
            if(d[e[i]]>d[t]+c[i]){
                d[e[i]]=d[t]+c[i];
                if(!inq[e[i]]) inq[e[i]]=1,q.push(e[i]);
            }
        }
    }
    for(i=1;i<=m;i++){
    	x=eg[i][0];y=eg[i][1];z=eg[i][2];
    	if(d[x]+z==d[y]) ind[y]++;
    }
    q.push(S);f[S]=1;
    while(!q.empty()){
        t=q.front();q.pop();
        for(i=head[t];i;i=nex[i])
            if(d[e[i]]==d[t]+c[i]){
                upd(f[e[i]],f[t]);
                if(--ind[e[i]]==0) q.push(e[i]);
            }
    }
}
int main(){
    int i,x,y,z,S,T,t,ans;
    scanf("%d %d %d %d",&n,&m,&S,&T);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&x,&y,&z);
        eg[i][0]=x,eg[i][1]=y,eg[i][2]=z;
        eg[i+m][0]=y,eg[i+m][1]=x,eg[i+m][2]=z;
        adde(x,y,z);adde(y,x,z);
    }
    m*=2;
    spfa(S,T,d1,f);
    spfa(T,S,d2,g);
    ans=(ll)f[T]*f[T]%mod;
    for(i=1;i<=m;i++){
        x=eg[i][0];y=eg[i][1];z=eg[i][2];
        if(d1[x]*2<d1[T]&&d1[y]*2>d1[T]&&d1[x]+d2[y]+z==d1[T])
            ans=((ans-(ll)f[x]*f[x]%mod*g[y]%mod*g[y]%mod)%mod+mod)%mod;
    }
    for(i=1;i<=n;i++)
        if(d1[i]*2==d1[T]&&d2[i]*2==d1[T]) ans=((ans-(ll)f[i]*f[i]%mod*g[i]%mod*g[i]%mod)%mod+mod)%mod;
    printf("%d",ans);
    return 0;
}
