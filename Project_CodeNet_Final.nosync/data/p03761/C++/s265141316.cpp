#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  ll n;
  cin >> n;
  
  string S;
  vl com(26, 100);
  
  rep(i, n){
    cin >> S;
    ll len = S.size();
    map<ll, ll> cnt;

    rep(j, len) cnt[S[j] - 'a']++;

    rep(j, 26) com[j] = min(com[j], cnt[j]);
  }
  
  rep(i, 26){
    rep(j, com[i]){
      cout << (char)(i + 'a');
    }
  }
  
  cout << endl;
  
  return 0;
}