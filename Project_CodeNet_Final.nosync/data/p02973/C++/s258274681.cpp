#include <bits/stdc++.h>
using namespace std;
template <typename T> bool chmax(T &u, const T z) { if (u < z) {u = z; return true;} else return false; }
template <typename T> bool chmin(T &u, const T z) { if (u > z) {u = z; return true;} else return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long 
int INF=INT_MAX;
int main(){
  ll n;
  cin>>n;
  vector<int>a(n);
  multiset<int>m;
  rep(i,n)cin>>a[i];
  int kotae=0;
  rep(i,n){
    auto Iter = m.lower_bound(a[i]);
    if(Iter!=m.begin())m.erase(--Iter);
    m.insert(a[i]);
  }
  kotae=m.size();
  cout<<kotae<<endl;
  return 0;
}
