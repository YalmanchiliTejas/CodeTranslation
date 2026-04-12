#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,pset[100007];
long long x[100007],y[100007],ans=0;
pair < pair < long long,long long > , int > p[100007];
vector < pair < long long, pair < int,int > > > cur;
int fset(int x){
    if(pset[x]==x) return x;
    return pset[x]=fset(pset[x]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        p[i]=mp(mp(x[i],y[i]),i);
        pset[i]=i;
    }
    sort(p+1,p+1+n);
    for(int i=2;i<=n;i++){
        cur.pb(mp(p[i].fi.fi-p[i-1].fi.fi,mp(p[i].se,p[i-1].se)));
    }
    for(int i=1;i<=n;i++){
        p[i]=mp(mp(y[i],x[i]),i);
    }
    sort(p+1,p+1+n);
    for(int i=2;i<=n;i++){
        cur.pb(mp(p[i].fi.fi-p[i-1].fi.fi,mp(p[i].se,p[i-1].se)));
    }
    sort(cur.begin(),cur.end());
    for(int i=0;i<cur.size();i++){
        int a=cur[i].se.fi,b=cur[i].se.se;
        long long val=cur[i].fi;
        a=fset(a);
        b=fset(b);
        if(a!=b){
            pset[b]=a;
            ans+=val;
        }
    }
    cout<<ans;
}
