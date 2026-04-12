#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  ll N,X,M,c=0,lp,st,lpp;
  cin >> N >> X >> M;
  map<ll,ll> mp;
  mp[X] = c;
  vector<ll> A(M+100),S(M+100);
  A[0] = X;
  S[0] = X;
  while(1){
    c++;
    X = (X*X)%M;
    if(mp.count(X)){
      lp = c - mp.at(X);
      st = mp.at(X);
      lpp = S.at(c-1);
      if(st > 0) lpp -= S.at(st-1);
      break;
    }
    mp[X] = c;
    A[c] = X;
    S[c] = S[c-1] + A[c];
    //cout << A[c] << "--";
  }
  ll ans=0,lpc = (N-st)/lp;
  ans += lpc*lpp;
  //cout << ";;" << lpp << endl;
  if(st > 0) ans += S.at(st-1);
  ll ret = (N-st)%lp;
  if(ret + st > 0) ans += S.at(ret + st-1);
  if(st > 0) ans -= S.at(st-1);
  cout << ans;
  return 0;
}