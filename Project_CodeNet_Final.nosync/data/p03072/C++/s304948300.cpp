#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0;i < (n);i++)
using namespace std;
  
int main () {
  int n, s=0, count=0;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a.at(i);
  rep(i,n) {
    if(s <= a.at(i)) {
      count++;
    }
    s = max(s,a.at(i));
  }
    cout << count;
}
