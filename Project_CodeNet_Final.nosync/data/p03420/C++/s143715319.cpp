#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;


int main(){
  ll N, K;
  cin >> N >> K;

  ll ret = 0;
  REP(i,1,N+1){
    if(i==1){
      if(K==0) ret += N;
    }else{

      ll a = N/i;
      ll b = N%i;
      
      ret += max(0LL,i-K)*a;
      if(K==0){
        ret += b;
      }else{
        ret += max(0LL, b+1-K);
      }
    }
  }

  cout << ret << endl;
  
  return 0;
}

