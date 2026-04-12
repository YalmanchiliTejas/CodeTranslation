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
  vector<ll>mx;
  vector<ll>sum;
  Seg(){
    sum.resize(1<<19, 0);
    mx.resize(1<<19, 0);
  }

  void add_val(ll l, ll r, ll val, ll bottom=0, ll top=1<<18, ll pos=1){
    if(l<= bottom && top <= r){
      sum[pos] += val;
      return;
    }
    if(l>=top || r<= bottom)return;

    ll mid = (bottom+ top)/2;
    add_val(l, r, val, bottom, mid, pos*2);
    add_val(l, r, val, mid, top, pos*2+1);
    mx[pos] = max<ll>( mx[pos*2]+sum[pos*2], mx[pos*2+1]+sum[pos*2+1] );
  }

  ll max_val(ll l, ll r, ll bottom=0, ll top=1<<18, ll pos=1){
    if(l<= bottom && top <= r) return mx[pos]+sum[pos];
    if(l>=top || r<= bottom)return -INF;

    ll mid = (bottom+ top)/2;
    return max<ll>(
      max_val(l, r, bottom, mid, pos*2),
      max_val(l, r, mid, top, pos*2+1)
    )+sum[pos];
  }
};

int main(){
  int n,m;cin>>n>>m;
  vector<pll> score[n+1];
  rep(i, m){
    ll l,r,a;cin>>l>>r>>a;
    score[r].push_back({l, a});
  }

  Seg seg;

  rep1(i, n){
    ll mx = seg.max_val(0, i);
    seg.add_val(i, i+1, mx);
    for(auto p:score[i]){
      ll l = p.first;
      ll a = p.second;
      seg.add_val(l, i+1, a);
    }
  }

  cout<<seg.max_val(0, n+1);

  return 0;
}