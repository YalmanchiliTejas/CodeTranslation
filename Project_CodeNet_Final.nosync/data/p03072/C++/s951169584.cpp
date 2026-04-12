#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n;
int ans = 1;
int maxh;

int main(){
  cin >> n;
  vector<int> h(n);
  rep(i, n) cin >> h.at(i);
  maxh = h.at(0);
  for(int i = 1; i < n; i++){
    if(maxh <= h.at(i)){
      ans++;
      maxh = h.at(i);
    }
  }
  cout << ans << endl;
}