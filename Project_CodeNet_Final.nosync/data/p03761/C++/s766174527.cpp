#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using vpii = vector<pair<int, int>>;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep1(i, n) for (int i = 1; i < (int)n; i++)
ll inf = 1e9+7;

ll gcd(ll a, ll b){
  return (b != 0) ? gcd(b, a%b) : a;
}

ll lcm(ll a, ll b){
  return (a/gcd(a,b))*b;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  vector<vector<int>> cnt(n, vector<int>(30, 0));
  rep(i, n){
    for(const auto& x : s[i]) ++cnt[i][x-'a'];
  }
  vector<int> mincnt(30, 60);
  rep(i, 27) rep(j, n) mincnt[i] = min(mincnt[i], cnt[j][i]);
  for(char i = 'a'; i <= 'z'; ++i){rep(j, mincnt[i-'a']) cout << i;}
  return 0;
}   