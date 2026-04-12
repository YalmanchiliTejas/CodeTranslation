#include <bits/stdc++.h>
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define IFOR(i, m, n) for(int i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
/* テンプレートここまで */

int main() {
  ll N; cin >> N;
  deque<ll> a(N); REP(i, N) cin >> a[i];
  sort(ALL(a));
  vector<ll> b(2);
  ll ans = a.back() - a.front();
  b[0] = a.front();
  b[1] = a.back();
  a.pop_back(); a.pop_front();
  
  while(!a.empty()){
    vector<ll> tmp(4);
    tmp[0] = abs(a.back() - b[0]);
    tmp[1] = abs(a.back() - b[1]);
    tmp[2] = abs(b[0] - a.front());
    tmp[3] = abs(b[1] - a.front());
    auto it = max_element(ALL(tmp));
    ans += *it;
    ll i = it - tmp.begin();
    if(i==0){
      b[0] = a.back();
      a.pop_back();
    }else if(i==1){
      b[1] = a.back();
      a.pop_back();
    }else if(i==2){
      b[0] = a.front();
      a.pop_front();
    }else{
      b[1] = a.front();
      a.pop_front();
    }
  }
  cout << ans << endl;
}
