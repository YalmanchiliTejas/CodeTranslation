#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX=100020;
const int INF=1987654321;
struct town{
    int x,y,idx;
};
struct edge{
    int a,b,dist;
    bool operator<(const edge &p)const{
        return dist>p.dist;
    }
};
town a[MAX];
int chk[MAX];
bool cmp_x(town &a,town &b){
    return a.x<b.x;
}
bool cmp_y(town &a,town &b){
    return a.y<b.y;
}
int dist(town &a,town &b){
    return min(abs(a.x-b.x),abs(a.y-b.y));
}
vector<pii> conn[MAX];
priority_queue<edge> mst;
ll ans;
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",&a[i].x,&a[i].y),a[i].idx=i+1;
    sort(a,a+n,cmp_x);
    for(int i=0;i<n-1;i++) {
        conn[a[i].idx].push_back(make_pair(a[i+1].idx,dist(a[i],a[i+1])));
        conn[a[i+1].idx].push_back(make_pair(a[i].idx,dist(a[i],a[i+1])));
    }
    sort(a,a+n,cmp_y);
    for(int i=0;i<n-1;i++) {
        conn[a[i].idx].push_back(make_pair(a[i+1].idx,dist(a[i],a[i+1])));
        conn[a[i+1].idx].push_back(make_pair(a[i].idx,dist(a[i],a[i+1])));
    }
    edge origin={0,0,INF};
    for(int i=1;i<=n;i++){
        for(int j=0;j<conn[i].size();j++) if(origin.dist>conn[i][j].second) origin={i,conn[i][j].first,conn[i][j].second};
    }
    mst.push(origin);
    while(!mst.empty()){
        edge tmp=mst.top();
        mst.pop();
        if(chk[tmp.a]==0||chk[tmp.b]==0){
            ans+=(ll)tmp.dist;
            if(chk[tmp.a]==0){
                chk[tmp.a]=1;
                for(int i=0;i<conn[tmp.a].size();i++) if(chk[conn[tmp.a][i].first]==0) mst.push({tmp.a,conn[tmp.a][i].first,conn[tmp.a][i].second});
            }
            if(chk[tmp.b]==0){
                chk[tmp.b]=1;
                for(int i=0;i<conn[tmp.b].size();i++) if(chk[conn[tmp.b][i].first]==0) mst.push({tmp.b,conn[tmp.b][i].first,conn[tmp.b][i].second});
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
