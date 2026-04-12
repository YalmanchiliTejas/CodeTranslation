#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int n;
struct node{
    int x,y,id;
}e[N];
bool cmp1(node a,node b){
    return a.x<b.x;
}
bool cmp2(node a,node b){
    return a.y<b.y;
}
struct qnode{
    int from,to,w;
    qnode(int a=0,int b=0,int c=0){from=a,to=b,w=c;}
    bool operator < (const qnode &b)const{
        return w>b.w;
    }
};
priority_queue<qnode>q;int fa[N];
void init(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&e[i].x,&e[i].y),e[i].id=i;fa[i]=i;
    }
    sort(e+1,e+n+1,cmp1);
    for(int i=1;i<n;i++){
        q.push(qnode(e[i].id,e[i+1].id,e[i+1].x-e[i].x));
    }
    sort(e+1,e+1+n,cmp2);
    for(int i=1;i<n;i++){
        q.push(qnode(e[i].id,e[i+1].id,e[i+1].y-e[i].y));
    }
}

int fi(int x){
    if(fa[x]==x)return x;
    else return fa[x]=fi(fa[x]);
}
int main()
{
    init();
    ll ans=0;
    while(!q.empty()){
        int u=q.top().from,v=q.top().to,w=q.top().w;q.pop();
        int f1=fi(u),f2=fi(v);
        if(f1!=f2){
            ans+=w;
            fa[f1]=f2;
        }
    }
    cout<<ans<<endl;
}
