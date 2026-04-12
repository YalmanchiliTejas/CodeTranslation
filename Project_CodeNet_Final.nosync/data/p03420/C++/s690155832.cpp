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

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
const ll INF = INT_MAX;

int main() {
  ll N,K;
  cin >> N >> K;
  ll ans = 0;
  if(K==0){
    ans = N*N;
  }else{
    for(ll b = K+1;b<=N;b++){
      ll q = (b-K)*((N-K)/b+1);
      ll r = (N-K)%b;

      if(r<=b-1-K){
        q -= (b-1-K-r);
      }
      ans += q;
    }
  }
  cout << ans << endl;
  return 0;
}
