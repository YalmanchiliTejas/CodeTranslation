#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = INT_MAX;
const ll MOD = 1e9+7;


int main() {
  int N;cin >> N;
  vll a(N);
  repeat(i,N){
    cin >> a[i];
  }
  ll ans = 0;
  ll S=1;
  while(S>0){
    S = 0;
    repeat(i,N){
      S += a[i]/N;
    }
    ans += S;
    repeat(i,N){
      a[i] += (S-(a[i]/N))-(a[i]/N)*N;
    }
  }
  cout << ans << endl;
  return 0;
}
