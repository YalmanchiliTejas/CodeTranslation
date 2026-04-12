#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<long long,long long> ii;
vector<pair<long long,ii>> edge;
long long n,up[100005],sz[100005];
pair<ii,long long> x[100005];

bool cmp(const pair<ii,long long> &a,const pair<ii,long long> &b){
    return a.fi.fi<b.fi.fi;
}
bool cmp1(const pair<ii,long long> &a,const pair<ii,long long> &b){
    return a.fi.se<b.fi.se;
}
int findSet(int x){
    if(x==up[x]) return x;
    else return findSet(up[x]);
}
void unionSet(int x,int y){
    long long x1=findSet(x),y1=findSet(y);
    if(sz[x1]<sz[y1]) swap(x1,y1);
    up[y1]=x1;
    sz[x1]+=sz[y1];
}
bool checkSet(int x,int y){
    long long x1=findSet(x),x2=findSet(y);
    if(x1==x2)
        return 1;
    else
        return 0;
}
int main(){
    cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i].fi.fi>>x[i].fi.se;
        x[i].se=i;
    }
    sort(x+1,x+1+n,cmp);
    for(int i=1;i<=n;i++){
        up[i]=i;
        sz[i]=1;
    }
    for(int i=1;i<n;i++){
        long long x1=x[i].se,x2=x[i+1].se;
        long long val=abs(x[i].fi.fi-x[i+1].fi.fi),val1=abs(x[i].fi.se-x[i+1].fi.se);
        edge.pb(mp(val,mp(x1,x2)));
    }
    sort(x+1,x+1+n,cmp1);
    for(int i=1;i<n;i++){
        long long x1=x[i].se,x2=x[i+1].se;
        long long val=abs(x[i].fi.fi-x[i+1].fi.fi),val1=abs(x[i].fi.se-x[i+1].fi.se);
        edge.pb(mp(val1,mp(x1,x2)));
    }
    long long sum=0;
    sort(edge.begin(),edge.end());
    for(int i=0;i<edge.size();i++){
        long long x1=edge[i].se.fi,x2=edge[i].se.se;
        if(checkSet(x1,x2)==0){
            unionSet(x1,x2);
            sum+=edge[i].fi;
        }
    }
    cout<<sum;
}
