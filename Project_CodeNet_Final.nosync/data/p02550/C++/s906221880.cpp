#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  ll N, X, M;
  cin >> N >> X >> M;
  
  vector<ll> next(M, -1);
  
  ll pos = X, ans = 0, kaisu = 0;
  while (next.at(pos) == -1){
    ll num = (pos * pos) % M;
    next.at(pos) = num;
    ans += pos;
    pos = num;
    kaisu++;
    if (kaisu == N){
      cout << ans << endl;
      exit(0);
    }
  }
  
  ll loopbegin = pos, loopsum = pos, loopnow = pos, loopsize = 1;
  while (next.at(loopnow) != loopbegin){
    loopsum += next.at(loopnow);
    loopnow = next.at(loopnow);
    loopsize++;
  }
  
  ll loopnum = (N - kaisu) / loopsize;
  ans += loopnum * loopsum;
  
  ll nokori = N - kaisu - loopsize * loopnum;
  loopnow = loopbegin;
  for (ll i = 0; i < nokori; i++){
    ans += loopnow;
    loopnow = next.at(loopnow);
  }
  
  cout << ans << endl;
}