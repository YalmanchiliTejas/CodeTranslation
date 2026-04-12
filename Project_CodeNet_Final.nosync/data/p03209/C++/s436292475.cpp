#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <string>
#include <utility>
#include <vector>
#define pq priority_queue
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

const int iinf = 1 << 29;
const long long linf = 1ll << 61;
ll P[51];
ll T[51];

ll solve(ll n, ll X){
  if(n==0){
    if(X<=0) return 0;
    else return 1;
  }
  if (X<=1+T[n-1]){
    return solve(n-1,X-1);
  }
  return P[n-1]+1+solve(n-1,X-2-T[n-1]);
}

int main(){
  ll N,X;
  cin>>N>>X;
  P[0]=1;
  T[0]=1;
  for (int i = 0; i < N; i++) {
    P[i+1]=2*P[i]+1;
    T[i+1]=2*T[i]+3;
  }
  cout<<solve(N,X)<<endl;
}
