#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int>a(n);
  rep(i,0,n) cin >> a[i];
  deque<int>d;
  rep(i,0,n){
    int p = lower_bound(d.begin(),d.end(),a[i])-d.begin();
    if(p == 0) d.push_front(a[i]);
    else d[p-1] = a[i];
  }
  cout << d.size() << endl;
}