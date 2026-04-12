#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n; cin >> n;
  vi a(n); rep(i,n) cin >> a[i];

  ll ans = 0;
  rep(i,2){
    if(i) sort(all(a),greater<int>());
    else sort(all(a));
    list<int> lst;
    int l = 0, r = n-1;
    lst.push_front(a[l]);
    l++;
    while(1){
      lst.push_front(a[r]);
      r--;
      if(r < l) break;
      lst.push_back(a[r]);
      r--;
      if(r < l) break;
      lst.push_front(a[l]);
      l++;
      if(r < l) break;
      lst.push_back(a[l]);
      l++;
      if(r < l) break;
    }
    ll res = 0, pre = -1;
    for(auto now : lst){
      if(pre != -1) res += abs(now-pre);
      pre = now;
    }
    chmax(ans,res);
  }
  cout << ans;
  cout << "\n";
  return 0;
}
