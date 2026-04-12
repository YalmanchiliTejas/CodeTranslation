#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define fi first
#define se second
#define mp make_pair
#define itrfor(itr,A) for(auto itr = A.begin(); itr !=A.end();itr++)
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
template<class T> bool chmax(T &a,  T b) {if(a<b){a=b; return 1;} return 0;}
template<class T> bool chmin(T &a,  T b) {if(a>b){a=b; return 1;} return 0;}
bool Add(int &a,int b){a = (a + b) % MOD;}
void myprint(int* A,int A_num){
   REP(i,A_num) cout << A[i] << " ";
   cout << endl;
}

const int n_max = 1004;

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


llong beki(llong a,llong x){
    llong res = 1;
    llong tmp = a;
    while(x > 0){
        if(x & 1) res *= tmp; res %= MOD;
        tmp *= tmp;
        tmp %= MOD;
        x >>=1;
    }
    return res;
}

signed main(){
    int n,a,b,c,d;
    cin >> n >> a >>b >> c >> d;
    init();

    int dp[n_max][n_max];
    REP(i,n_max) REP(j,n_max) dp[i][j] = 0;
    int gyakugen[n_max];
    FOR(i,1,n_max) gyakugen[i] = beki(i,MOD-2);

    dp[b][n] = 1;
    REPR(i,b){
        if(i == a-1) break;

        REP(j,n + 1){
            dp[i - 1][j] += dp[i][j];
            dp[i-1][j] %= MOD;
            int tmp = 1;
            FOR(k,1,d+1){
                if(k * i > j) break;
                tmp *= nCk(i * k,i);
                tmp %= MOD;
                tmp *= gyakugen[k];
                tmp %= MOD;
                if(k < c) continue; 
                int hoge = dp[i][j] * tmp;
                hoge %= MOD;
                hoge *= nCk(j,k * i);
                hoge %= MOD;
                dp[i-1][j-k * i] += hoge;
                dp[i-1][j-k * i] %= MOD;
            }
        }
    }
    cout << dp[a-1][0] << endl;


}