#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<'\n';
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    multiset<ll> cnt;
    rep(i,n){
      ll a;
      cin>>a;
      if(i==0){
        cnt.insert(a);
        continue;
      }
      auto itr=cnt.lower_bound(a);
      if(itr==begin(cnt)){
        cnt.insert(a);
        continue;
      }
      //cout<<' '<<*itr<<endl;
      itr--;
      if(*itr>=a) cnt.insert(a);
      else{
        cnt.erase(itr);
        cnt.insert(a);
      }
      /*
      for(auto itr:cnt) cout<<itr<<' ';
      cout<<endl;
      */
    }
    cout<<len(cnt)<<endl;
}