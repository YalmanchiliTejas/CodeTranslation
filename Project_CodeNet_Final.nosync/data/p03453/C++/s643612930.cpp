#include<bits/stdc++.h>
//ios::sync_with_stdio(false);
//cin.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> ppll;
typedef pair<ll,pll> plpl;
typedef tuple<ll,ll,ll> tl;
ll mod=1000000007;
ll mod2=998244353;
ll mod3=1000003;
ll mod4=998244853;
ll inf=1000000000000000000;
double pi=2*acos(0);
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,n,m) for(ll i=n;i>=m;i--)
int dh[4]={1,-1,0,0};
int dw[4]={0,0,1,-1};
int ddh[8]={-1,-1,-1,0,0,1,1,1};
int ddw[8]={-1,0,1,-1,1,-1,0,1};
ll lmax(ll a,ll b){
    if(a<b)return b;
    else return a;
}
ll lmin(ll a,ll b){
    if(a<b)return a;
    else return b;
}
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(a%b==0)return b;
    return gcd(b,a%b);
}
ll Pow(ll n,ll k){
    ll ret=1;
    ll now=n;
    while(k>0){
        if(k&1)ret*=now;
        now*=now;
        k/=2;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;cin>>n>>m;
    ll s,t;cin>>s>>t;
    vector<pll> v[n+1];
    rep(i,0,m){
        ll a,b,c;cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    pll ds[n+1],dt[n+1];
    fill(ds,ds+n+1,make_pair(inf,0));
    fill(dt,dt+n+1,make_pair(inf,0));
    ds[s]={0,1};
    dt[t]={0,1};
    priority_queue<pll,vector<pll>,greater<pll>> q;
    q.push({0,s});
    while(q.size()>0){
        pll p=q.top();q.pop();
        ll now=p.second;
        ll dis=p.first;
        ll num=ds[now].second;
        rep(i,0,v[now].size()){
            ll di=v[now][i].second;
            ll ne=v[now][i].first;
            if(ds[ne].first>dis+di){
                ds[ne]={dis+di,num};
                q.push({dis+di,ne});
            }
            else if(ds[ne].first==dis+di){
                ll uu=ds[ne].second;
                ds[ne]={dis+di,(uu+num)%mod};
            }
        }
    }
    q.push({0,t});
    while(q.size()>0){
        pll p=q.top();q.pop();
        ll now=p.second;
        ll dis=p.first;
        ll num=dt[now].second;
        rep(i,0,v[now].size()){
            ll di=v[now][i].second;
            ll ne=v[now][i].first;
            if(dt[ne].first>dis+di){
                dt[ne]={dis+di,num};
                q.push({dis+di,ne});
            }
            else if(dt[ne].first==dis+di){
                ll uu=dt[ne].second;
                dt[ne]={dis+di,(uu+num)%mod};
            }
        }
    }
    ll ans=ds[t].second;
    ans=(ans*ans)%mod;
    ll y=ds[t].first;
    priority_queue<pll> qq;
    qq.push({ds[t].first,t});
    bool used[n+1];
    fill(used,used+n+1,false);
    rep(i,1,n+1){
        //cout<<ds[i].first<<" "<<ds[i].second<<endl;
    }
    rep(i,1,n+1){
       // cout<<dt[i].first<<" "<<dt[i].second<<endl;
    }
    while(qq.size()>0){
        pll p=qq.top();qq.pop();
        ll now=p.second;
        ll dis=p.first;
        if(used[now])continue;
        used[now]=true;
       // cout<<dis<<endl;
        if(ds[now].first*2<y)continue;
        if(ds[now].first*2==y){
            ll sum=ds[now].second*dt[now].second;
            sum%=mod;
            sum*=sum;
            sum%=mod;
            ans=ans-sum+mod;
            ans%=mod;
            continue;
        }
        rep(i,0,v[now].size()){
            
            ll ne=v[now][i].first;
            ll di=v[now][i].second;
            if(ds[ne].first+di!=ds[now].first)continue;
            if(ds[now].first*2>y&&ds[ne].first*2<y){
                ll sum=ds[ne].second*dt[now].second;
                sum%=mod;
                sum*=sum;
                sum%=mod;
                ans=ans-sum+mod;
                ans%=mod;
                
            }
            if(used[ne]==false)qq.push({ds[ne].first,ne});
        }
    }
    cout<<ans<<endl;
}
