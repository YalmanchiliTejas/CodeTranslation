#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = (int)(0); i < (int)(n); ++i)
using ll = long long;

signed main()
{
  int n; cin>>n;
  vector<int> a(n);
  rep(i,n) cin>>a[i];
  deque<int> d;
  rep(i,n){
    int p = lower_bound(d.begin(),d.end(),a[i]) - d.begin(); // a[i]以上の最小値が登場するインデックス
    if(p==0){
      d.push_front(a[i]);
    }else d[p-1]=a[i];
  }
  int ans=d.size();
  cout<<ans<<endl;
}