#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
const int N=1e5+5;
struct node{
    int u,v,w;
    bool operator<(const node&a)const{return w<a.w;}
}e[N*2];
int se[N];
int get(int x){
    while(x!=se[x])
        x=se[x]=se[se[x]];
    return x;
}
struct point{
    int w,id;
    bool operator<(const point&a)const{return w<a.w;}
}x[N],y[N];
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x[i].w,&y[i].w);
        x[i].id=y[i].id=i;
        se[i]=i;
    }
    sort(x+1,x+n+1),sort(y+1,y+n+1);
    int ct=0;
    for(int i=1;i<n;i++) e[++ct]=(node){x[i].id,x[i+1].id,abs(x[i].w-x[i+1].w)};
    for(int i=1;i<n;i++) e[++ct]=(node){y[i].id,y[i+1].id,abs(y[i].w-y[i+1].w)};
    sort(e+1,e+ct+1);
    long long sum=0;
    int cnt=1;
    for(int i=1;i<=ct;i++){
        int fu=get(e[i].u),fv=get(e[i].v);
        if(fu==fv)continue;
        sum+=e[i].w;
        se[fu]=fv;
        if(++cnt==n) break;
    }
    cout<<sum;
}
