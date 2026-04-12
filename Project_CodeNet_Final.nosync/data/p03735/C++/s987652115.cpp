//#include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//#include "boost/multiprecision/cpp_int.hpp"
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
typedef pair<dd,dd> d_d;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fi first
#define se second
///////////////////////////

#define N 200005
ll n;
l_l x[N];

ll solve(){
     //cin>>n;
     ll mi=0,ma=0;
     rep(i,0,n-1){
         //cin>>x[i].fi>>x[i].se;
         if(x[i].fi>x[i].se)swap(x[i].se,x[i].fi);
     }
    rep(i,0,n-1){
        if(x[i].fi<x[mi].fi)mi=i;
        if(x[i].se>x[ma].se)ma=i;
     }
     ll ans1=inf,ans2=inf;
     ll rmax=x[ma].se,bmin=x[mi].fi;
     ll rmin=inf,bmax=-inf;
     if(mi!=ma){
         rmin=x[mi].se;
         bmax=x[ma].fi;
     }
     rep(i,0,n-1){
         if(i==mi||i==ma)continue;
         Min(rmin,x[i].se);
         Max(bmax,x[i].fi);
     }
     ans1=(rmax-rmin)*(bmax-bmin);
     bool chanflag=true;
     if(mi==ma)chanflag=false;
     if(!chanflag)rep(i,0,n-1){
         if(i==mi)continue;
         if(x[mi].fi==x[i].fi){
             mi=i;
             chanflag=true;
             break;
         }
     }
     if(!chanflag)rep(i,0,n-1){
         if(i==ma)continue;
         if(x[ma].se==x[i].se){
             ma=i;
             chanflag=true;
             break;
         }
     }
    if(!chanflag){return ans1;}
     rmax=x[ma].se;
     rmin=x[mi].fi;
     bmax=x[ma].fi;bmin=x[mi].se;
     if(bmax<bmin)swap(bmax,bmin);
     vector<l_l>vpre;
     rep(i,0,n-1){
         if(i==mi||i==ma)continue;
         if(x[i].fi<bmin&&bmax<x[i].se){
             vpre.pb(x[i]);
         }else if(bmax<x[i].fi){
             bmax=x[i].fi;
         }else if(x[i].se<bmin){
             bmin=x[i].se;
         }
     }
    vector<l_l>v;
    for(auto z:vpre){
        if(z.fi<bmin&&bmax<z.se)v.pb(z);
    }
     sort(v.begin(),v.end());
     ll vs=v.size();
     ll dp[vs+1];
     dp[0]=bmax;
     rep(i,0,vs-1){
         dp[i+1]=max(dp[i],v[i].se);
     }
     ll dismin=inf;
     rep(i,0,vs){
         if(i==vs)Min(dismin,dp[i]-bmin);
         else Min(dismin,dp[i]-v[i].fi);
     }
     ans2=dismin*(rmax-rmin);
     //cout<<ans1<<" "<<ans2<<endl;
     return min(ans1,ans2);
}

ll solve2(){
    ll res=inf;
    rep(i,0,(1<<n)-1){
        ll rmax=-inf,rmin=inf,bmax=-inf,bmin=inf;
        rep(j,0,n-1){
            ll r=x[j].fi;
            ll b=x[j].se;
            if((i>>j)&1)swap(r,b);
            Max(rmax,r);Min(rmin,r);
            Max(bmax,b);Min(bmin,b);
        }
        Min(res,(rmax-rmin)*(bmax-bmin));
    }
    return res;
}

int main(){fastio
    /*
    n=4;
    rep(kai,1,1000){
        rep(i,0,n-1){
            x[i].fi=rand()%10+1;
            x[i].se=rand()%10+1;
        }
        ll a=solve();
        ll b=solve2();
        if(a!=b){
            cout<<"!"<<endl;
     cout<<"ans is"<<a<<" "<<b<<endl;
            rep(i,0,n-1)cout<<x[i].fi<<" "<<x[i].se<<endl;
            cout<<"!"<<endl;
        }
        
    }*/
    //cout<<"finish";
    inf=(ll)1E18+5;
    cin>>n;
    rep(i,0,n-1)cin>>x[i].fi>>x[i].se;
    cout<<solve()<<endl;
    
    return 0;
}
/*
 4
1 5
4 8
3 6
2 2
 
 
 
 */
