#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define fi first
#define se second
#define mp make_pair
#define itrfor(itr,A) for(auto itr = A.begin(); itr !=A.end();itr++)
#define dame { printf("No\n"); return 0;}
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;
typedef long long llong;
char moji[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char moji2[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char moji3[10]={'0','1','2','3','4','5','6','7','8','9'};
#define Sort(a) sort(a.begin(),a.end());
#define Reverse(a) reverse(a.begin(),a.end());
#define print(a) cout << a << endl;
#define MOD llong(1e9+7)
#define MAX int(2 * 1e5 +5)
#define debug(x)  cout << #x << " = " << (x) << endl;
#define pi acos(-1.0)
#define int llong
#define INF llong(1e17)


#define n_max llong(2e5 + 5)



llong fac[n_max];  /// fac[n] = n!
llong finv[n_max]; /// (fac[n] * finv[n]) % MOD = 1
llong inv[n_max];  /// (n * inv[n]) % MOD = 1
 
void init() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  FOR (i, 2, n_max) {
    fac[i] = fac[i-1]*i % MOD;
    inv[i] = MOD - inv[MOD%i]*(MOD/i) % MOD;
    finv[i] = finv[i-1]*inv[i] % MOD;
  }
}
 
llong nCk (int n, int k) {
  if (n < k || k < 0 || n < 0) return 0;
  return fac[n]*finv[k]%MOD*finv[n-k]%MOD;
}


signed main(){
    init();
    int n,m,k;
    cin >> n >> m >> k;
    int yoko_ki = m * m % MOD;
    int yokowa = 0;
    int tmp = 0;
    REP(i,n){
        tmp += i;
        yokowa += tmp;
        tmp %= MOD;
        yokowa %= MOD;
    }
    yoko_ki = yoko_ki * yokowa % MOD;

    int tate_ki = n * n % MOD;
    int tatewa = 0;
    tmp = 0;
    REP(i,m){
        tmp += i;
        tatewa += tmp;
        tmp %= MOD;
        tatewa %= MOD;
    }
    tate_ki = tate_ki * tatewa % MOD;
    


    int ki = tate_ki + yoko_ki;
    if(k == 2){
        cout << ki << endl;
    }
    else{
        ki *= nCk(n * m - 2,k-2);

        cout << ki % MOD << endl;
    }
}
