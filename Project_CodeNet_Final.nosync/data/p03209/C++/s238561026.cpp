#include <bits/stdc++.h>
using namespace std;

# define ll long long

vector<ll> buns, patties;

ll findPatties(int N, ll X) {
  if(N == 0) {
    return 1;
  }
  if(X <= 1 && N > 0) {
    return 0;
  }
  
  ll length = buns[N] + patties[N];
  ll prevLength = buns[N-1] + patties[N-1];
  
  if(X == length/2+1) {
    return patties[N]-patties[N-1];
  }
  if(X > length/2+1) {
    return patties[N-1] + 1 + findPatties(N-1, X-(length/2+1));
  }
  
  return findPatties(N-1, X-1);
}

int main() {
	ll N, X;
  cin >> N >> X;
  
  buns.push_back(0);
  patties.push_back(1);
  
  for(int i = 1; i < N+1; i++) {
    buns.push_back(buns[i-1]*2+2);
    patties.push_back(patties[i-1]*2+1);
  }
  
  ll ans = findPatties(N, X);
  
  cout << ans << endl;
  
  return 0;
}
