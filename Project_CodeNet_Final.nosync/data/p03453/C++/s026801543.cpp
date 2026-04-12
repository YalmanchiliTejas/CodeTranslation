#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,int> PLI;
const int MAXN=100005;
const int MAXM=200005;
const LL INF=1e18;
const int mod=1e9+7;

vector<PLI > edge[MAXN];
int n,m,s,t;
LL e[MAXM][3];
LL dis1[MAXN],dis2[MAXN];
LL num1[MAXN],num2[MAXN];

priority_queue<PLI,vector<PLI>,greater<PLI> > pq; 
void SPFA(int s,LL* dis,LL* num){
    for(int i=1;i<=n;i++){
        num[i]=0;
        dis[i]=INF;
    }
    dis[s]=0; num[s]=1;
    pq.push(PLI(0,s));
    while(!pq.empty()){
        PLI a=pq.top(); pq.pop();
        int u=a.second;
        if (dis[u]<a.first) continue;
        for(int i=0;i<edge[u].size();i++){
            int v=edge[u][i].first;
            LL d=edge[u][i].second;
            if (dis[v]>=dis[u]+d){
                if (dis[v]>dis[u]+d) num[v]=num[u],pq.push(PLI(dis[u]+d,v));
                else (num[v]+=num[u])%=mod;
                dis[v]=dis[u]+d;
            }
        }
    }
}

int main(){    
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++){
        int a,b,c; scanf("%d%d%d",&a,&b,&c);
        e[i][0]=a; e[i][1]=b; e[i][2]=c;
        edge[a].push_back(PLI(b,c));
        edge[b].push_back(PLI(a,c));
    }
    SPFA(s,dis1,num1);
    SPFA(t,dis2,num2);
    LL ans=num1[t]*num2[s]%mod;    
    LL ans1=0;
    for(int i=1;i<=n;i++){
        if (dis1[i]==dis2[i] && dis1[i]+dis2[i]==dis1[t]){
            LL tmp=num1[i]*num2[i]%mod;
            ans-=tmp*tmp%mod;
            if (ans<0) ans+=mod;
        }
    }
    //LL ans2=0;
    for(int i=1;i<=m;i++){
        LL a,b,c; a=e[i][0]; b=e[i][1]; c=e[i][2];
        if (dis1[a]>dis1[b]) swap(a,b);
        if (dis1[a]*2<dis1[t] && dis2[b]*2<dis1[t] && dis1[a]+dis2[b]+c==dis1[t]){
            LL tmp=num1[a]*num2[b]%mod;
            ans-=tmp*tmp%mod;
            if (ans<0) ans+=mod;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
