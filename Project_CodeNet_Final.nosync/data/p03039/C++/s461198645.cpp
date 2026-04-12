#include<bits/stdc++.h>
using namespace std;
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, n) for(int i = 0;i < (n);++i)
#define RREP(i, n) for(int i = (n)-1; i >= 0; --i)

#define endl '\n'
#define pb push_back
#define eb emplace_back
#define prique priority_queue
#define umap unordered_map
#define BIG 2000000000
#define VERYBIG 1000000000000000ll
#define PI 3.1415926
#define coutdb cout<<fixed<<setprecision(15)

const int dx[]={1,0,-1,0,1,1,-1,-1}, dy[]={0,-1,0,1,1,-1,1,-1};
const long long MOD = 1e9+7;

// typedef int_fast64_t ll;
#define int int_fast64_t
using Graph = vector<vector<int> >;
typedef pair<int, int> P;

template<typename T> inline T GCD(T a,T b){T c;while(b!=0){c=a%b;a=b;b=c;}return a;}
template<typename T> inline T LCM(T a,T b){T c=GCD(a,b);a/=c;return a*b;}
template<typename T> inline T nCr(T a,T b){T i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
template<typename T> inline T nHr(T a,T b){return nCr(a+b-1,b);}

const int MAX_N = 210000;
int fact[MAX_N], revfact[MAX_N];

int powmod(int a, int p){
  int res = 1, tmp = a;
  while(p != 0){
    if(p % 2) res = (res*tmp) % MOD;
    tmp = (tmp*tmp) % MOD;
    p /= 2;
  }
  return res;
}
 
void factmod(){
  fact[0] = revfact[0] = 1;
  for(int i = 1; i < MAX_N; i++){
    fact[i] = (fact[i-1] * i) % MOD;
    revfact[i] = (revfact[i-1] * powmod(i, MOD-2)) % MOD;
  }
}
 
int nCrmod(int n, int r){ // nCr % MOD
  return (((fact[n] * revfact[r]) % MOD) * revfact[n-r]) % MOD;
}

signed main(void){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M, K; cin >> N >> M >> K;
  factmod();
  int ans = 0;
  for(int d = 1; d < N; d++){
    int num = d*(N-d)*M*M % MOD;
    ans += num; ans %= MOD;
  }
  for(int d = 1; d < M; d++){
    int num = d*(M-d)*N*N % MOD;
    ans += num; ans %= MOD;
  }
  cout << (ans*nCrmod(N*M-2, K-2)) % MOD << endl;
}
