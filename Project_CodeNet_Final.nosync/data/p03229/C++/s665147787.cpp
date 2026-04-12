#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){

  int n;
  cin >> n;
  vector<ll> v(n);
  rep(i,n)scanf("%d",&v[i]);
  sort(ALL(v));
  ll l = v[0],r = v.back();
  ll res = r-l;
  for(int i = 0,j = n-1;i < j;i++,j--){
    if(i & 1){
      res += v[j]-l;
      res += r-v[i];
      l = v[j];
      r = v[i];
    }else{
      res += l-v[i];
      res += v[j]-r;
      l = v[i];
      r = v[j];
    }
  }
  if(n & 1)res += max(abs(l-v[n/2]),abs(r-v[n/2]));
  cout << res << endl;
  




  return 0;
}