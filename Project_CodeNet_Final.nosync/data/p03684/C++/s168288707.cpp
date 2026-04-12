#include <iostream>
#include <algorithm>
#include <cstdio>
#define rush() int T;cin>>T;while(T--)
#define go(a) while(cin>>a)
#define ms(a,b) memset(a,b,sizeof a)
#define E 1e-8
using namespace std;
typedef long long ll;
const int N=1e5+5;

    int n,m,t;
    int fa[N];
    int i,j,k;
struct point
{
    int x,y,id;
}p[N];
struct Edge
{
    int u,v,valu;
    bool const operator<(const Edge &b)
    const{
        return valu<b.valu;
    }
}edge[N];
int Find(int son)
{
    return son==fa[son] ? son : fa[son]=Find(fa[son]);
}
bool Union(int x,int y)
{
    x=Find(x),y=Find(y);
    if(x==y) return 1;
    else{
        fa[y]=x;
        return 0;
    }
}
bool cmpx(point &a,point &b){
    return a.x<b.x;
}
bool cmpy(point &a,point &b){
    return a.y<b.y;
}
int main()
{
    cin.tie(0);istream::sync_with_stdio(false);
    while(cin>>n){
        for(i=1;i<=n;i++) fa[i]=i;

        for(i=1;i<=n;i++){
            cin>>p[i].x>>p[i].y;
            p[i].id=i;
        }

        int num=0;
        sort(p+1,p+1+n,cmpx);//尽量以x之间的距离为经费建路
        for(i=1;i<n;i++){
            edge[++num].u=p[i].id;
            edge[num].v=p[i+1].id;
            edge[num].valu=min(abs(p[i].x-p[i+1].x),abs(p[i].y-p[i+1].y));
        }
        sort(p+1,p+1+n,cmpy);//尽量以y之间的距离为经费建路
        for(i=1;i<n;i++){
            edge[++num].u=p[i].id;
            edge[num].v=p[i+1].id;
            edge[num].valu=min(abs(p[i].x-p[i+1].x),abs(p[i].y-p[i+1].y));
        }

        stable_sort(edge+1,edge+1+num);
        int ans=0,cnt=0;
        for(i=1;i<=num;i++){
            if(0==Union(edge[i].u,edge[i].v)){//若u，v两点还未连接
                ans+=edge[i].valu;
                cnt++;
            }
            if(cnt==n-1) break;//建路数达到联通所有城市
        }
        cout<<ans<<endl;
    }
}