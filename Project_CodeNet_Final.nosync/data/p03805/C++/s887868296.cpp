#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()



int main(){
  ll N,M,ans=0;
  cin >> N >> M;
  vector<vector<ll>> V(N,vector<ll>(N,0));
  rep(i,M){
    ll a,b;
    cin >> a >> b;
    V.at(a-1).at(b-1)=1;
    V.at(b-1).at(a-1)=1;
  }
  vector<ll> v(N);
  rep(i,N) v.at(i)=i;
  do {
    ll t=0;
    rep(i,N-1){
      if(V.at(v.at(i)).at(v.at(i+1))!=1){
        t=1;
        break;
      }
    }
    if(t==0){
      ans++;
    }
  } while (next_permutation(v.begin()+1, v.end()));
  cout << ans << endl;
}
  
  