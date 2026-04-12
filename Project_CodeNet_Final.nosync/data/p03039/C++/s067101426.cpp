#include <bits/stdc++.h>
#define SORT(x) sort((x).begin(),(x).end())
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < n; i++)
#define reps(i, m, n) for(ll i = m; i < n; i++)
#define repr(i, m, n) for(int i = m; i >= n; i--)
template<class T>bool maxi(T &a,const T &b){if(a<b){ a=b; return 1;} return 0;}
template<class T>bool mini(T &a,const T &b){if(b<a){ a=b; return 1;} return 0;}
#define y0 y3487465 //j0
#define j1 j1347829 //j1
#define INF2 4000000000000000037
#define INF 1000000007
#define PI (acos(-1))
#define MOD 1000000007
using namespace std;
typedef long long ll;

const int MAX = 200010;
ll fac[MAX], finv[MAX], inv[MAX];
void cinit() { // O(nlogn)
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  reps(i, 2, MAX){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}
ll c(int n, int k){ // 二項係数計算
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

void Main(){

  cinit();

  ll N,M,K; cin>>N>>M>>K;

  ll ans=0;

  ans=(c(N*M-2,K-2));

  ll temp=0;

  reps(d,1,M){
    temp=(temp+(d*(M-d)%MOD)*(N*N%MOD))%MOD;
  }
  reps(d,1,N){
    temp=(temp+(d*(N-d)%MOD)*(M*M%MOD))%MOD;
  }

  cout<< ans*temp%MOD <<"\n";

}

//-----------------------------------
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  Main();
}
//-----------------------------------
