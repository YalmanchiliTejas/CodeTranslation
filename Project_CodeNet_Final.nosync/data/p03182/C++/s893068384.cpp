#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

struct Seg{
  vector<ll> mx, sum;
  Seg(){
    mx.resize(1<<19);
    sum.resize(1<<19);
  }

  void add(ll l, ll r, ll score, ll pos=0, ll bottom=0, ll top=1<<18){
    if(top <= l || r <= bottom)return;
    if(l <= bottom && top <= r){sum[pos]+=score; return;}

    ll mid = (bottom+top)/2;
    add(l, r, score, pos*2+1, bottom, mid);
    add(l, r, score, pos*2+2, mid, top);
    mx[pos] = max<ll>(mx[pos*2+1]+sum[pos*2+1], mx[pos*2+2]+sum[pos*2+2]);
  }

  ll mxv(ll l, ll r, ll pos=0, ll bottom=0, ll top=1<<18){
    if(top <= l || r <= bottom)return -INF;
    if(l <= bottom && top <= r)return mx[pos]+sum[pos];

    ll mid = (bottom+top)/2;
    return max<ll>(
      mxv(l, r, pos*2+1, bottom, mid),
      mxv(l, r, pos*2+2, mid, top)
    )+sum[pos];
  }
};

int main(){
  ll n,m;cin>>n>>m;
  vector<vector<pll>>is(1<<20);
  rep(i, m){
    ll l,r,a;cin>>l>>r>>a;
    is[r].push_back({l, a});
  }

  Seg seg;

  rep1(r, n){
    ll mx = seg.mxv(0, r);
    seg.add(r, r+1, mx);
    for(auto p: is[r]){
      ll l=p.first;
      ll a = p.second;
      seg.add(l, r+1, a);
    }
  }

  cout<<seg.mxv(0, n+1)<<endl;

  return 0;
}