//10のi乗pow(10, i);
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int>h(n);
  rep(i,n) cin>>h.at(i);
  int count=0;
  int ma = h.at(0);
  rep(i,n){
    if(ma<=h.at(i)) count++;
    ma = max(ma,h.at(i));
  }
  cout << count << endl;
}
