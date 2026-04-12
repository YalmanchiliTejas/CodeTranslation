#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;
typedef unsigned long long ull;

ll M=1000000007;

int main(){
  int N;
  cin >> N;
  vector<ll> A(N);
  //vector<vector<ll>> As(N, vector<ll>(N));
  vector<ll> Sums(N);
  ll ans=0;
  rep(i,N) {
    cin >> A.at(i);
  }

  for(int i = N-2; i >= 0; --i){
    Sums.at(i) = (Sums.at(i+1) + A.at(i+1)) % M;
  }


  rep(i,N){
    ans = (ans + Sums.at(i) * A.at(i))%M;
  }
  cout << ans << endl;
}
