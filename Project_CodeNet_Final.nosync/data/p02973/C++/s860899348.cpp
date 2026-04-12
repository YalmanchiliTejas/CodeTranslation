#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ull = long long unsigned;
using P = pair<int,int>;
const int INF=1001001;
const int NMAX=8;
const int mod = 1000000007;

int main()
{
  int n;
  cin>>n;
  vector<int>a(n);
  rep(i,n)cin>>a[i];
  deque<int>d;
  rep(i,n){
    int idx=lower_bound(d.begin(),d.end(),a[i])-d.begin();
    if (idx==0) d.push_front(a[i]);
    else{
      d[idx-1]=a[i];
    }
  }
  cout<<d.size();



}
