//Sequence Sum 

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define nnn "\n"
#define spa " "
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

//n=元の数,p=乗数,m=mod
ll repsqr(ll n,ll p,ll m){
    if(p==0)return 1;
    if(p%2==0){
        ll t=repsqr(n,p/2,m);
        return t*t%m;
    }
    return n*repsqr(n,p-1,m)%m;
}

signed main (){
    int n,x,m;cin>>n>>x>>m;
    map<int,int>t;
    int l=x;t[l]++;
    while(t[repsqr(l,2,m)]<2){
        l=repsqr(l,2,m);
        t[l]++;
    }
    int r=0,rk=0,ok=0;
    if(t.size()==1){
        for(auto i:t)cout<<n*i.first<<nnn;
        return 0;
    }
    for(auto i:t){
        if(i.second==2)r+=i.first,rk++;
        else ok++;
    }
    int ans=0;
    if(ok<n)ans+=((n-ok)/rk)*r;
    int o=((n-ok)%rk)+ok;
    ans+=x;l=x;
    rep(i,1,o){
        l=repsqr(l,2,m);
        ans+=l;
    }
    cout<<ans<<nnn;
    return 0;
}