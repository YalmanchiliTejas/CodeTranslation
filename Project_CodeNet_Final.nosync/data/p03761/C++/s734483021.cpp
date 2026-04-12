#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
  int n;
  cin >> n;
  vector<vi> v(n,vector<int>(200,0));
  rep(i,n) {
    string s;
    cin >> s;
    rep(j,s.size()) v[i][(int)s[j]]++;
  }
  vector<int> ans(200);
  for(int i = (int)'a'; i <= (int)'z'; i++) {
    rep(j,n) {
      if(j==0) ans[i] = v[j][i];
      else ans[i] = min(ans[i],v[j][i]);
    }
  }
  for(int i = (int)'a'; i <= (int)'z'; i++) {
    rep(j,ans[i]) cout << (char)i;
  }
  cout << endl;
  return 0;
}