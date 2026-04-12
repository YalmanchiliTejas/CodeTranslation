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

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  ll n,x,m; cin >> n >> x >> m;
  vi num;
  map<int,int> mp;
  while(1){
    if(mp[x] == 2) break;
    num.push_back(x);
    mp[x]++;
    x = x*x%m;
  }
  int once = 0, twice = 0;
  for(auto a : mp){
    if(a.second == 1) once++;
    if(a.second == 2) twice++;
  }
  ll start = 0, roop = 0;
  vi one,two;
  rep(i,num.size()){
    if(i < once){
      one.push_back(num[i]);
      start += num[i];
    }
    if(once <= i && i < once+twice){
      two.push_back(num[i]);
      roop += num[i];
    }
  }
  ll ans = 0;
  if(n <= once){
    rep(i,once) ans += one[i];
  }else{
    ans += start;
    n -= once;
    ans += roop*(n/twice);
    n %= twice;
    rep(i,n){
      ans += two[i];
    }
  }
  cout << ans;
  return 0;
}
