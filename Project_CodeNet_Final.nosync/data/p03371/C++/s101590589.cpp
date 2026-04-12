#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

int main(){
  ll A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  ll Z = max(X,Y);
  ll ans = INF;
  for(ll i = 0; i <= Z; i++){
    ll p = C*(2LL*i)+max((X-i),0LL)*A+max(0LL,(Y-i))*B;
    chmin(ans,p);
  }
  cout<<ans<<endl;
}