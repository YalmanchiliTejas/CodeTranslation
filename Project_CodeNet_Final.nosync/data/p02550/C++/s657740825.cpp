#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;

int main() {
  ll N,X,M, shuuki=0, start=0, shuu=0;
  cin >> N >> X >> M;
  vector<ll> V(0);
  set<ll> ss;
  ll A=X, B;
  V.push_back(A);
  ss.insert(A);
  for (ll i=2; i<M+30; i++) {
    //cout << A << endl;
    B=A*A;
    B=B-B/M*M;
    ss.insert(B);
    if (ss.size()!=i) {
      for (ll j=0; j<V.size(); j++) {
        if (V[j]==B) {
          start=j;
          shuuki=V.size()-j;
          shuu=1;
          //cout << shuuki << endl;
        }
      }
      break;
    }
    V.push_back(B);
    A=B;
    if (V.size()==N) {
      shuu=0;
      break;
    }
  }
  if (shuu==1) {
    ll S=0, SS=0;
    for (ll i=0; i<start; i++) {
      SS+=V[i];
    }
    for (ll i=start; i<V.size(); i++) {
      S+=V[i];
    }
    N-=start;
    ll a=N/shuuki;
    ll b=N-N/shuuki*shuuki;
    ll s=0;
    for (ll i=start; i<b+start; i++) {
      s+=V[i];
    }
    cout << SS+s+S*a << endl;
    //cout << a << endl;
  }
  else {
    ll SSS=0;
    for (ll i=0; i<V.size(); i++) {
      SSS+=V[i];
    }
    cout << SSS << endl;
  }
}