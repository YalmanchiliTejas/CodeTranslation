
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<numeric>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main () {
  int n,cnt = 0,c = 0;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; i++){
    cin >> h[i];
    if (h[i] >= cnt){
      c++;
      cnt = h[i];
    }
  }
  cout << c << '\n';
  return 0;
}