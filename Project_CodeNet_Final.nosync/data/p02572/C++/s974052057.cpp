#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  ll p = 1000000007;
  ll p2 = p*2;

  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a.at(i);
  }

  ll sum = 0;
  ll sum_s = 0;
  rep(i,n){
    sum += a.at(i);
    sum %= p2;
    sum_s += (ll)a.at(i)*(ll)a.at(i);
    sum_s %= p2;
  }


  int sqr = (sum*sum)%p2;
  int ans2 = sqr - sum_s;
  while(ans2<0)  ans2+=p2;
  int ans = ans2/2;
  cout << ans;
}