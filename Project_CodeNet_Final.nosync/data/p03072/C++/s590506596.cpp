#include <bits/stdc++.h>
#include <boost/multi_array.hpp>
#define rep(i,n) for (int i=0; i< (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i,n){
    cin >> h[i];
  }
  vector<int> l(n+1);
  l[0] = 0;
  rep(i,n){
    l[i+1] = max(l[i],h[i]);
  }
  int count = 1;
  for(int i=1;i<n;i++){
    if (h[i]>=l[i]) count++;
  }
  cout << count << endl;
  return 0;
}
