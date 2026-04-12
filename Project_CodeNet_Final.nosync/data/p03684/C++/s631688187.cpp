#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second

const int N=1e5+5;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

int n,ans;
int pset[N],s[N];
vector<ii> vx,vy;
map<ii,int> ma;
priority_queue<iii,vector<iii>,greater<iii> > pq;

bool how_sort(ii a,ii b){
    if(a.se!=b.se)
            return a.se<b.se;
    return a.fi<b.fi;
}

int unionfind(int u){
    return (u==pset[u]) ? u : (pset[u]=unionfind(pset[u]));
}
bool compare(int u,int v){
    return (unionfind(u)==unionfind(v)) ? true :false;
}
void unionset(int i,int j)
{
    int x=unionfind(i),y=unionfind(j);
    if(s[x]>s[y]){
        pset[y]=x;
        s[x]+=s[y];
    }
    else{
        pset[x]=y;
        s[y]+=s[x];
    }
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int cnt=0;
    cin>>n;
    for(int i=1;i<=n;++i){
        int a,b;
        cin>>a>>b;
        if(ma[ii(a,b)])continue;
        ma[ii(a,b)]=++cnt;
        vx.pb(ii(a,b));
        vy.pb(ii(a,b));
        pset[cnt]=cnt;
        s[cnt]=1;
    }
    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end(),how_sort);
    
	
    for(int i=1;i<vx.size();++i){
        int a=vx[i].fi-vx[i-1].fi;
        pq.push(iii(a,ii(ma[vx[i]],ma[vx[i-1]])));
	
        int b=vy[i].se-vy[i-1].se;
        pq.push(iii(b,ii(ma[vy[i]],ma[vy[i-1]])));
    }
    while(!pq.empty()){
        iii x=pq.top();
        int w=x.fi,u=x.se.fi,v=x.se.se;
        pq.pop();
        if(!compare(u,v)){
            unionset(u,v);
            ans+=w;
        }
    }
    cout<<ans;
}
