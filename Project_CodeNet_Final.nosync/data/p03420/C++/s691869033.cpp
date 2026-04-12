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
  ll N,K;
  cin >> N >> K;
  ll ans=0;
  ll tmp1,tmp2;
  if(K==0) cout << N*N;
  else{
  FOR(i,K+1,N+1){
    tmp1=N/i;
    tmp2=N%i;
    ans+=(i-K)*tmp1;
    if(tmp2>=K) ans+=(tmp2-K+1);
  }
  cout << ans;
}
}
