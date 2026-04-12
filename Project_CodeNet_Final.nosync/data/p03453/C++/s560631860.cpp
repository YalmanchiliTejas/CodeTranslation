#include<bits/stdc++.h>
#include <cstring>
#include <iostream>
#define pie acos(-1)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b)
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b)
#define slll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define ss(st) scanf("%s",st)
#define sch(ch) scanf("%ch",&ch)
#define ps(a) printf("%s",a)
#define newLine() printf("\n")
#define pi(a) printf("%d",a)
#define pii(a,b) printf("%d %d",a,b)
#define piii(a,b,c) printf("%d %d %d",a,b,c)
#define pl(a) printf("%lld",a)
#define pll(a,b) printf("%lld %lld",a,b)
#define plll(a,b,c) printf("%lld %lld %lld",a,b,c)
#define pd(a) printf("%lf",a)
#define pdd(a,b) printf("%lf %lf",a,b)
#define pddd(a,b,c) printf("%lf %lf %lf",a,b,c)
#define pch(c) printf("%ch",c)
#define debug1(str,a) printf("%s=%d\n",str,a)
#define debug2(str1,str2,a,b) printf("%s=%d %s=%d\n",str1,a,str2,b)
#define debug3(str1,str2,str3,a,b,c) printf("%s=%d %s=%d %s=%d\n",str1,a,str2,b,str3,c)
#define debug4(str1,str2,str3,str4,a,b,c,d) printf("%s=%d %s=%d %s=%d %s=%d\n",str1,a,str2,b,str3,c,str4,d)
#define for0(i,n) for(i=0;i<n;i++)
#define for1(i,n) for(i=1;i<=n;i++)
#define forab(i,a,b) for(i=a;i<=b;i++)
#define forstl(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define NL puts("")
#define sd(a) scanf("%lf",&a)
#define sdd(a,b) scanf("%lf %lf",&a,&b)
#define sddd(a,b,c) scanf("%lf %lf %lf",&a,&b,&c)
#define SP printf(" ")
#define LL long long int
#define ULL unsigned long long int
#define MOD 1000000007
#define pub(x) push_back(x)
#define pob(x) pop_back(x)
#define mem(ara,value) memset(ara,value,sizeof(ara))
#define INF INT_MAX
#define eps 1e-8
#define checkbit(n, pos) (n & (1<<pos))
#define setbit(n, pos) (n | (1<<pos))
#define para(a,b,ara)\
for(int i=a;i<=b;i++){\
    if(i!=0){printf(" ");}\
    printf("%d",ara[i]);\
}\
printf("\n");
#define pvec(vec)\
for(int i=0;i<vec.size();i++){\
    if(i!=0){printf(" ");}\
    printf("%d",vec[i]);\
}\
printf("\n");
#define ppara(n,m,ara)\
for(int i=0;i<n;i++){\
    for(int j=0;j<m;j++){\
        if(j!=0){printf(" ");}\
        printf("%d",ara[i][j]);\
    }\
    printf("\n");\
}
#define ppvec(n,vec)\
for(int i=0;i<n;i++){\
    for(int j=0;j<vec[i].size();j++){\
        if(j!=0){printf(" ");}\
        printf("%d",vec[i][j]);\
    }\
    printf("\n");\
}
#define sara(a,b,ara)\
for(int i=a;i<=b;i++){\
    scanf("%d",&ara[i]);\
}
using namespace std;
struct edge{
    LL vt,wt;
    edge(){}
    edge(LL _vt,LL _wt){
        vt=_vt;wt=_wt;
    }
};
struct compare{
    int operator()(const struct edge &lhs,const struct edge &rhs){
        return lhs.wt>rhs.wt;
    }
};
LL n,m,st,en;
vector <edge> adj[100010];
LL way[2][100010];
LL best[2][100010];
void input(){
    LL i,j,u,v,w;
    sll(n,m);
    sll(st,en);st--;en--;
    for0(i,n+2){adj[i].clear();}
    for0(i,m){
        slll(u,v,w);u--;v--;
        adj[u].pub(edge(v,w));adj[v].pub(edge(u,w));
    }
//    ps("sajib\n");
}
void djkstra(bool fl,LL source){
    LL i,j,u,c;
    edge temp;
    mem(way[fl],0);
    mem(best[fl],-1);
    priority_queue<edge,vector<edge>,compare> q;
    while(!q.empty()){q.pop();}
    way[fl][source]=1;
    best[fl][source]=0;
    q.push(edge(source,0));
//    ps("sajib");
    while(!q.empty()){
        temp=q.top();q.pop();
        if(temp.wt>best[fl][temp.vt]){continue;}
//        pl(temp.vt);NL;
        for0(i,adj[temp.vt].size()){
            u=adj[temp.vt][i].vt;
            if((temp.wt+adj[temp.vt][i].wt<best[fl][u])||best[fl][u]==-1){
                way[fl][u]=way[fl][temp.vt]%MOD;
//                way[fl][u]=0;
                best[fl][u]=temp.wt+adj[temp.vt][i].wt;
                q.push(edge(u,temp.wt+adj[temp.vt][i].wt));
            }
            else if(temp.wt+adj[temp.vt][i].wt==best[fl][u]){
                way[fl][u]=((way[fl][u]%MOD)+(way[fl][temp.vt]%MOD))%MOD;
            }
        }
    }
}
LL bigMod(LL x,LL p){
    if(p==0){return 1;}
    LL s=bigMod(x,p/2);
    if(p%2==0){
        return ((s%MOD)*(s%MOD))%MOD;
    }
    else{
        return ((((s%MOD)*(s%MOD))%MOD)*(x%MOD))%MOD;
    }
}
void solve(){
    LL i,j,u,mns=0,tinv=bigMod(2,MOD-2)%MOD;
//    ps("sajib\n");
    djkstra(false,st);
    djkstra(true,en);

    LL s1,s2,s3,s4,s5,s6;
//    para(0,n-1,best[false]);
//    para(0,n-1,best[true]);
//    para(0,n-1,way[false]);
//    para(0,n-1,way[true]);
    for0(i,n){
        for0(j,adj[i].size()){
            u=adj[i][j].vt;
            if(best[false][i]<(best[false][en]+1)/2&&best[true][u]<(best[false][en]+1)/2){
                if(best[false][i]+best[true][u]+adj[i][j].wt==best[false][en]){
//                    pll(i,u);NL;
                    s1=way[false][i];
                    s2=way[true][u];
                    s3=((s1%MOD)*(s2%MOD))%MOD;
                    s5=((s3%MOD)*(s3%MOD))%MOD;
    //                s6=((s5%MOD)*(tinv%MOD))%MOD;
                    mns=((mns%MOD)+(s5%MOD))%MOD;

                }
            }
        }
    }
    if(best[false][en]%2==0){
        for0(i,n){
            if(best[false][i]==best[true][i]&&best[false][i]==best[false][en]/2){
                s1=way[false][i];
                s2=way[true][i];
                s3=((s1%MOD)*(s2%MOD))%MOD;
                s5=(s3*s3)%MOD;
                mns=((mns%MOD)+(s5%MOD))%MOD;
            }
        }
    }
//    pl(mns);NL;
//    pl(way[false][en]*way[true][st]);NL;
    LL ans=(way[false][en]*way[true][st])%MOD;
    ans=(ans-mns+MOD)%MOD;
    pl(ans);NL;
}
int main(){
//    freopen("input.txt","r",stdin);
    input();
    solve();
    return 0;
}
