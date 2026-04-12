#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  deque<int> q;
  
  rep(i,n){
    int p = lower_bound(q.begin(),q.end(),a[i]) - q.begin();
    if(p==0){
      q.push_front(a[i]);
    }else{
      q[p-1] = a[i];
    }
  }
  int ans = q.size();
  cout << ans << endl;
}
