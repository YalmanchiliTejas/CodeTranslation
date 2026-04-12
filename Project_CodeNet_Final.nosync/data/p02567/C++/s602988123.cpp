#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
typedef int64_t ll;

ll op(ll a,ll b){return max(a,b);}
ll e(){return -1;}
ll t,x,y;
bool f(ll a){return (a<y ? 1 : 0);}

int main(){
  ll n,q;
  cin>>n>>q;
  vector<ll> a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  atcoder::segtree<ll,op,e> seg(a);
  for(int i=0;i<q;i++){
    cin>>t>>x>>y;
    if(t==1){x--;seg.set(x,y);}
    if(t==2){x--;cout<<seg.prod(x,y)<<endl;}
    if(t==3){x--;cout<<seg.max_right<f>(x)+1<<endl;}
  }
}
