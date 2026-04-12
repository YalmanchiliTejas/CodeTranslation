#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back
#define eb pb

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define EFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i, n) for (int i=0; i<(n); i++)
#define REP rep
#define int long long
typedef long long ll;
typedef ll LL;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> inline bool MX(T&l, const T&r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T&l, const T&r){return l>r?l=r,1:0;}
int N;
//int cel[114514];
const int SIZE=1e6+500;
//int Solve() {
 //     }
 // return ans;
//}
LL A[SIZE];
vector<int> primes;
bool notprimes[SIZE];
signed main() {
  cin >> N;  
  EFOR(i,2,1e6){
    if(notprimes[i]==false){
      primes.pb(i);

      for(int j=i*i;j<1e6;j+=i){
        notprimes[j]=true;
      }
    }
  }

  REP(i,N) cin >> A[i];
  set<int> v;
  REP(i,N){
    LL x=A[i];
    REP(i,primes.size()){
      if(x%primes[i]==0){
        v.insert(primes[i]);
        while(x%primes[i]==0) x/=primes[i];
        
      }
      if(x!=1) v.insert(x);
    }

  }
  LL ans=0;
  for(auto p:v){
    LL x=0;
    REP(i,N) if(A[i]%p==0) x+=A[i]; 
    MX(ans,x);
  }

  cout << ans << endl;
}

