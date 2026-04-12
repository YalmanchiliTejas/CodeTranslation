#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> cnt(26);
  for(int i = 0; i < 26; i++) cnt[i] = 2000;

  string s;
  for(int i = 0; i < n; i++){

    cin >> s;
    vector<int> tmp_cnt(26);
    for(int j = 0; j < 26; j++) tmp_cnt[j] = 0;

    for(int j = 0; j < s.length(); j++){
      tmp_cnt[int(s[j]-'a')]++;
    }

    for(int j = 0; j < 26; j++){
      chmin(cnt[j], tmp_cnt[j]);
    }

  }

  string ans = "";
  for(int i = 0; i < 26; i++){
    for(int j = 0; j < cnt[i]; j++){
      ans += char(i + 'a');
    }
  }

  cout << ans << endl;

  return 0;
}
