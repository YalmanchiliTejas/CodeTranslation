#include "bits/stdc++.h"
#define PRECISION(x) cout << fixed << setprecision(x)
#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define ALLR(X) (X).rbegin(), (X).rend()
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define F first
#define S second

using namespace std;
 
template<class T> void max_self(T & a, const T & b) { if(a < b) a = b; }
template<class T> void min_self(T & a, const T & b) { if(a > b) a = b; }
typedef long long LL;
const int INF = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = (1e-9);

LL N, k, fl[55], f[55];

LL g(LL layer, int rank){
  if(rank == 0){
    return (layer > 0);
  }

  assert(rank >= 0);
//  assert(layer >= 0);

  if(layer <= 1 + fl[rank - 1]) return g(layer - 1, rank - 1);

  layer -= (2 + fl[rank - 1]);

  return 1LL + f[rank - 1] + g(layer, rank - 1);
}

int main(){
  FAST_IO

  cin >> N >> k;

  fl[0] = f[0] = 1;

  for(int rep = 1; rep <= N; ++rep){
    fl[rep] = 3 + 2LL * fl[rep - 1];
    f[rep] = 1 + 2LL * f[rep - 1];
  }

//  for(int rep = 0; rep <= N; ++rep){
//    cout << f[rep] << " " << fl[rep] << '\n';
//  }
//
//  cout << "\n-------------------\n";
//  for(int layer = 0; layer < 30; ++layer){
//    cout << g(layer, 3) << '\n'; 
//  }

  cout << g(k, N) << '\n';
  return 0;
}
