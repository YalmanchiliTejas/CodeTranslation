#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,ll> pll;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

struct LazySegmentTree{
private:
   int n;
   vector<ll> node,lazy;
public:
   LazySegmentTree(int sz,ll init=0){
      n=1;
      while(n<sz)n*=2;
      node.resize(2*n-1,init);
      lazy.resize(2*n-1,0);
   }

   void eval(int k,int l,int r){
      if(lazy[k]!=0)node[k]+=lazy[k];
      if(r-l>1){
          lazy[2*k+1]+=lazy[k];
          lazy[2*k+2]+=lazy[k];
      }
      lazy[k]=0;
   }
      //[a,b)にxを加算
   void add(int a,int b,ll x,int k=0,int l=0,int r=-1){
       if(r<0)r=n;
       eval(k,l,r);
       if(r<=a||b<=l)return;
       if(a<=l&&r<=b){
          lazy[k]+=x;
          eval(k,l,r);
       }
       else {
          add(a,b,x,2*k+1,l,(l+r)/2);
          add(a,b,x,2*k+2,(l+r)/2,r);
          node[k]=min(node[2*k+1],node[2*k+2]);
        }
   }
   //[a,b)でのminを返す
   ll get(int a,int b,int k=0,int l=0,int r=-1){
      if(r<0)r=n;
      eval(k,l,r);
      if(r<=a||b<=l)return longinf;
      if(a<=l&&r<=b)return node[k];
      ll xl=get(a,b,2*k+1,l,(l+r)/2);
      ll xr=get(a,b,2*k+2,(l+r)/2,r);
      return min(xl,xr);
   }
};

ll dp[202020];


int main(){
    int n,m;
    cin>>n>>m;
    vector<pll> a[n+1];
    ll ans=0;
    rep(i,m){
        int x,y,z;
        cin>>x>>y>>z;
        ans+=z;
        a[y].emplace_back(x,z);
    }
    rep(i,n+1)dp[i]=longinf;
    LazySegmentTree sg(n+1,0);
    dp[0]=0;
    rep(i,n){
        dp[i+1]=dp[i];
        sg.add(i+1,i+2,dp[i+1]);
        for(auto p:a[i+1])sg.add(0,p.first,p.second);
        dp[i+1]=min(dp[i+1],sg.get(0,i+1));
    }
    cout<<ans-dp[n]<<endl;
    return 0;
}