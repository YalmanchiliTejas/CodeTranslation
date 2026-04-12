#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Pair{
    int x,y;
}p[100005];
struct edge{
    int s,t,cost;
}e[2][100005];
int s[100005],t[100005],fa[100005];
int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}
bool Cmpx(int a,int b){
    return p[a].x<p[b].x;
}
bool Cmpy(int a,int b){
    return p[a].y<p[b].y;
}
bool Cmpe(edge a,edge b){
    return a.cost<b.cost;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i].x>>p[i].y;
        fa[i]=i;
        s[i]=i;t[i]=i;
    }
    sort(s,s+n,Cmpx);
    sort(t,t+n,Cmpy);
    for(int i=0;i<n-1;i++){
        e[0][i].s=s[i+1];
        e[0][i].t=s[i];
        e[0][i].cost=p[s[i+1]].x-p[s[i]].x;
    }
    for(int i=0;i<n-1;i++){
        e[1][i].s=t[i+1];
        e[1][i].t=t[i];
        e[1][i].cost=p[t[i+1]].y-p[t[i]].y;
    }
    sort(e[0],e[0]+n-1,Cmpe);
    sort(e[1],e[1]+n-1,Cmpe);
    int i=0,j=0,count=0;
    long long cost=0;
    while(count<n-1){
        if(i<=n-1&&e[0][i].cost<=e[1][j].cost){
            int x=Find(e[0][i].s),y=Find(e[0][i].t);
            fa[x]=y;
            cost+=e[0][i].cost;
        }else{
            int x=Find(e[1][j].s),y=Find(e[1][j].t);
            fa[x]=y;
            cost+=e[1][j].cost;
        }
        count++;
        while(i<n-1&&Find(e[0][i].s)==Find(e[0][i].t))i++;
        while(j<n-1&&Find(e[1][j].s)==Find(e[1][j].t))j++;
    }
    cout<<cost<<endl;
    return 0;
}
