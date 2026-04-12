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
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

vector<ll> all,pate;
ll ans = 0;
ll dfs(ll n, ll x){
  if(!n) return 0;
  if(x) x--;
  if(x){
    if(all[n-1] <= x){
      ans += pate[n-1];
      x -= all[n-1];
    }else{
      dfs(n-1,x);
      x = 0;
    }
  }
  if(x){ x--; ans++; }
  if(x){
    if(all[n-1] <= x){
      ans += pate[n-1];
      x -= all[n-1];
    }else{
      dfs(n-1,x);
      x = 0;
    }
  }
  if(x) x--;
  return ans;
}

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  ll n,x; cin >> n >> x;
  all = vector<ll>(n+1);
  pate = vector<ll>(n+1);
  all[0] = pate[0] = 1;
  rep(i,n){
    all[i+1] += all[i] * 2 + 3;
    pate[i+1] += pate[i] * 2 + 1;
  }
  cout << dfs(n,x);
  cout << "\n";
  return 0;
}
