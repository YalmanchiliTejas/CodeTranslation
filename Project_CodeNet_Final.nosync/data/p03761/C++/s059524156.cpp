#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (ll)1e18;

int main(){
  ll N; cin >> N;
  vector<ll> cmnstr(26, INF);
  
  for(ll i = 0; i < N; i++){
    string S; cin >> S;
    vector<ll> tmpstr(26, 0LL);
    for(char e : S){
      tmpstr[e - 'a']++;
    }
    for(ll a = 0; a < 26; a++){
      cmnstr[a] = min(tmpstr[a], cmnstr[a]);
    }
  }
  
  for(ll a = 0; a < 26; a++){
    char c = a + 'a';
    ll cnt = cmnstr[a];
    for(ll i = 0; i < cnt; i++){
      cout << c;
    }
  }
  return 0;
}