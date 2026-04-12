#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <numeric>
#include <iostream>

using namespace std;

#define FOR(i, a, b)   for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b)  for(int i = (a); i > (b); --i)
#define rep(i, n)	   for(int i = 0; i < (n); ++i)
#define all(c)		   begin(c), end(c)
#define rall(c)		   rbegin(c), rend(c)
#define SZ(a)		   ((ll) a.size())

typedef long long		   ll;
typedef unsigned long long ull;


int main(){
  int N;
  cin >> N;
  vector<ll> X(N);
  vector<ll> X2(N);
  rep(i,N){
    scanf("%lld",&X[i]);
  }
  copy(all(X),X2.begin());
  sort(all(X2));
  ll med1=X2[N/2-1];
  ll med2=X2[N/2];
  rep(i,N){
    if(X[i]<=med1) printf("%lld\n",med2);
    else if(X[i]>=med2) printf("%lld\n",med1);
  }
}
