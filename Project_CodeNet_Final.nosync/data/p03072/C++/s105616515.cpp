#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int>h(n);
  rep(i,n) cin >> h[i+1];
  int res = 1;
  int max_hight = h[1];
  for (int i = 2; i < (n+1); ++i){
    max_hight = max(max_hight, h[i]);
    if(max_hight <= h[i]) res++;
    else continue;
  }

  cout << res << endl;
  return 0;
}