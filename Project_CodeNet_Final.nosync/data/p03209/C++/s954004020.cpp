#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)

ll bsize(ll l){
  if(l==0){
    return 1;
  }
  return 3+bsize(l-1)*2;

}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,x;
    cin>>n>>x;

    vector<ll> p(51);
    vector<ll> b(51);
    p[0]=1;
    b[0]=1;
    FOR(i,1,51){
      p[i]+=p[i-1]*2+1;
      b[i]+=b[i-1]*2+3;
    }
    ll i=n;
    ll sum=0;
    ll res=0;
    while(sum<x){
      while(sum<x){
        if(sum+b[i]<=x){
          sum+=b[i];
          res+=p[i];
          break;
        }
        sum++;
        i--;
      }
      if(sum==x)break;
      res++;
      sum++;
    }

    cout<<res<<endl;

}
