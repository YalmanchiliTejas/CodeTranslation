#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define INF 1999999999
#define MODA 1000000007 
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main() {                                                                                                    
  ll N, X, M;
  cin >> N >> X >> M;

  vector<ll> Aibin(100001, 0);
  vector<ll> Aihist;
  ll Ai = X;
  Aibin[Ai]++;
  Aihist.push_back(Ai);
  ll i = 0;
  while (i < N) {
    Ai = (Ai*Ai)%M;
    if (Aibin[Ai] == 0) {
      Aibin[Ai]++;
      Aihist.push_back(Ai);
    }
    else {
      break;
    }
    i++;
  }
  ll itr = 0;
  // cerr << Ai << endl;
  while(true) {
    // cerr << Aihist[itr] <<" "<< itr << endl;
    if (Aihist[itr] != Ai) itr++;
    else break;
  }
  // cerr << Aihist.size() << endl;
  ll numitr = Aihist.size() - itr;
  ll numloop = (N - Aihist.size()) / numitr;
  ll rest = (N - Aihist.size()) % numitr;
  cerr << numitr <<" "<< numloop <<" "<< rest << endl;
  for(ll i = itr; i < Aihist.size(); ++i) {
    Aibin[Aihist[i]] += numloop;
  }
  for(ll i = itr; i < itr + rest; ++i) {
    Aibin[Aihist[i]] += 1;
  }
  ll ans = 0;
  for(ll i = 1; i < Aibin.size(); i++) {
    // if(Aibin[i] != 0) cerr << i <<" "<< Aibin[i] << endl;
    ans += i * Aibin[i];
  }
  cout << ans << endl;
  return 0;
}