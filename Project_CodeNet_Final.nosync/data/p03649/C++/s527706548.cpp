#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
using edge = pair<int, ll>;
using Graph = vector<vector<int>>; 
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
  ll n;cin >> n;
  vector<ll> a(n);
  for(int i = 0; i < n; ++i)cin >> a[i];
  
  ll ans = 0;
  bool f = true;
  while(f){
    for(int i = 0; i < n; ++i){
      ll d = a[i]/n;
      ll r = a[i]%n;
      a[i]= r;
      ans += d;
      for(int j = 0; j < n; ++j){
        if(i!=j) a[j] += d;
      }
    }
    f = false;
    for(int i = 0; i < n; ++i){
      if(a[i]>n-1)f = true;
    }
  }
  cout << ans << endl;
}
