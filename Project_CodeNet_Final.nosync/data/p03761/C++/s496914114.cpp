#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Sort(a) sort(a.begin(), a.end())
#define Reve(a) reverse(a.begin(), a.end())
typedef long long ll;
const ll MOD = 1e9+7;


int main(){
  int n, sz, t=0, sum=0;
  string s;
  cin >> n;
  vector<string> S(n);
  rep(i, n) cin >> S[i];
  vector<int> A(26, 100);
  rep(i, n){
    s = S[i];
    sz = s.size();
    for(char c='a'; c<='z'; c++){
      rep(j, sz){
        if(s.at(j)==c) sum++;
      }
      A[t] = min(A[t], sum);
      sum = 0;
      t++;
    }
    t = 0;
  }
  string ans=""; int m, g=0;
  for(char c='a'; c<='z'; c++){
    m = A[g];
    rep(i, m) ans += c;
    g++;
  }
  cout << ans << endl;
}
