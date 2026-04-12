#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }

vector<ll> p,all;
ll ans = 0;

void dfs(ll level, ll cnt){
  if(cnt) cnt--;
  if(level){
    if(all[level-1] <= cnt){
      cnt -= all[level-1];
      ans += p[level-1];
    }else{
      dfs(level-1,cnt);
      cnt = 0;
      level = 0;
    }
  }
  if(cnt){
    ans++;
    cnt--;
  }
  if(level){
    if(all[level-1] <= cnt){
      cnt -= all[level-1];
      ans += p[level-1];
    }else{
      dfs(level-1,cnt);
      cnt = 0;
      level = 0;
    }
  }
  if(cnt) cnt--;
}

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  ll n,x; cin >> n >> x;
  p = vector<ll>(n+1);
  all = vector<ll>(n+1);
  p[0] = all[0] = 1;
  rep(i,n){
    p[i+1] += p[i]*2+1;
    all[i+1] += all[i]*2+3;
  }
  dfs(n,x);
  cout << ans;
  cout << endl;
  return 0;
}
