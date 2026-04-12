#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;
const int MAX_N = 131072;

int main() {
  int N;
  cin>>N;
  vector<ll> v(N);
  for(int i = 0; i < N; i++) {
    cin>>v[i];
  }
  bool ok = false;
  ll ans = 0LL;
  while(!ok){
    ok=true;
    map<int,ll> m;
    ll cnt = 0LL;
    for(int i = 0; i < N; i++){
      if(v[i]>=N){
        ok=false;
        m[i]=v[i]/N;
        v[i]%=N;
        cnt+=m[i];
      }
    }
    for(int i = 0; i < N; i++){
      v[i]+=cnt-m[i];
    }
    ans += cnt;
  }
  cout<<ans<<endl;
}