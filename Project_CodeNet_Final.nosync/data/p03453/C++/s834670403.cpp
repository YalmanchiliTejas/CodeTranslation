
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E17;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
long double EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
////////////////////////////////////////

int main(){fastio;
    ll n,m;cin>>n>>m;
    ll s,t;cin>>s>>t;
    s--;t--;
    vector<l_l>v[n];
    rep(i,1,m){
        ll u,q,d;cin>>u>>q>>d;u--;q--;
        v[u].pb(l_l(d,q));
        v[q].pb(l_l(d,u));
    }
    ll md[n];fill(md,md+n,inf);
    md[s]=0;
    priority_queue<l_l,vector<l_l>,greater<l_l>>q;
    q.push(l_l(0,s));
    while(!q.empty()){
        l_l t=q.top();q.pop();
        ll nowp=t.second;
        for(auto xx:v[nowp]){
            ll to=xx.second,cost=xx.first;
            if(md[nowp]+cost<md[to]){
                md[to]=md[nowp]+cost;
                q.push(l_l(md[to],to));
            }
        }
    }
    
    
    ll com[n];memset(com,0,sizeof(com));
    com[s]=1;
    vector<l_l>jun;
    rep(i,0,n-1){
        jun.pb(l_l(md[i],i));
    }
    sort(jun.begin(),jun.end());
    rep(i,0,n-1){
        for(auto x:v[jun[i].second]){
            if(md[x.second]==md[jun[i].second]+x.first){
                Add(com[x.second],com[jun[i].second]);
            }
        }
    }
    ll ans=mod(com[t]*com[t]);
    
    ll comb[n];memset(comb,0,sizeof(comb));
    comb[t]=1;
    priority_queue<l_l>qb;
    qb.push(l_l(md[t],t));
    reverse(jun.begin(),jun.end());
    rep(i,0,n-1){
        for(auto x:v[jun[i].second]){
            if(md[x.second]==md[jun[i].second]-x.first){
                Add(comb[x.second],comb[jun[i].second]);
            }
        }
    }
    
    rep(i,0,n-1){
        if(md[i]*2==md[t]){
            Add(ans,-powl(mod(com[i]*comb[i]),2));
        }
    }
    rep(i,0,n-1){
        for(auto x:v[i]){
            if(md[i]*2<md[t]&&md[t]<md[x.second]*2&&md[i]+x.first==md[x.second]){
                Add(ans,-powl(mod(com[i]*comb[x.second]),2));
            }
        }
    }
    
    /*rep(i,0,n-1){
        cout<<com[i]<<" "<<comb[i]<<endl;
    }*/
    cout<<mod(ans)<<endl;
    
    return 0;
}
