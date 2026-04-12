#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+10;
const int maxn=1e5+10;
const int maxm=20;
const int mod=1e9+7;
const double pi=acos(-1.0);
int n;
struct node {
    int x,y;
    int id;
}town[maxn];
struct edge {
    int st,ed;
    int cost;
}e[maxn*4];
int fa[maxn];
bool cmp1(const node &a,const node &b) {
    return a.x<b.x;
}
bool cmp2(const node &a,const node &b) {
    return a.y<b.y;
}
bool cmp3(const edge &a,const edge &b) {
    return a.cost<b.cost;
}
int Find(int x)
{
    if(fa[x]!=x)
        fa[x]=Find(fa[x]);
    return fa[x];
}
int main() {
	cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> town[i].x >> town[i].y;
        town[i].id=i;
    }
    int k=0;
    sort(town+1,town+1+n,cmp1);
    for(int i=1;i<=n-1;i++) {
        e[k].st=town[i].id;
        e[k].ed=town[i+1].id;
        e[k++].cost=abs(town[i].x-town[i+1].x);
    }
    sort(town+1,town+1+n,cmp2);
    for(int i=1;i<=n-1;i++) {
        e[k].st=town[i].id;
        e[k].ed=town[i+1].id;
        e[k++].cost=abs(town[i].y-town[i+1].y);
	}
    sort(e,e+k,cmp3);
    for(int i=1;i<=n;i++)
        fa[i]=i;
	int ans=0;
	for(int i=0;i<k;i++) {
            int a=Find(e[i].st),b=Find(e[i].ed);
            if(a!=b) {
                ans+=e[i].cost;
                fa[b]=a;
            }
        }
    cout << ans;
    return 0;
}