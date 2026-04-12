#include<bits/stdc++.h>
#include <atcoder/all>
#define ll long long int
#define vec vector<ll>
#define mat vector<vector<ll>>

using namespace std;
using namespace atcoder;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

ll op(ll a,ll b) {
    return max(a, b);
  }

ll e() {
  return -1;
}
ll target;
bool f(ll a){
  return a<target;
}

int main(){

  ll n,q;
  cin >> n >> q;

  vec a(n);
  for(ll i=0;i<n;i++)cin >> a[i];

  segtree<ll, op, e> S(a);

  vec ans;

  for(ll i=0;i<q;i++){
    ll t,l,r;
    cin >> t >> l >> r;
    if(t==1){
      S.set(l-1,r);
    }
    else if(t==2){
      ans.push_back(S.prod(l-1,r));
    }
    else{
      target=r;
      ans.push_back(S.max_right<f>(l-1)+1);
    }
  }

  for(ll i=0;i<ans.size();i++)cout << ans[i] << endl;

}