#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define CLEAR(a) memset(a,0,sizeof a)
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define fr freopen("input.txt", "r", stdin);
#define fw freopen("output.txt", "w", stdout);
#define int long long 
typedef long long LL;
typedef pair<int,int> pii;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
int n,a,b,c,d, fac[MAX], invfac[MAX], dp[1001][1001], C[1001][1001];

int mod_pow(int base, int e){
    int ret =1;
    while(e){
        if(e%2) ret = (ret*base)%MOD;
        base = (base*base)%MOD;
        e /= 2;
    }
    return ret;
}

int inv(int x){
  return mod_pow(x, MOD-2);
}

int solve(int left, int i){
  
  if(left == 0) {
    return 1;
  }

  if(i > b || left < 0) {
    return 0;
  }

  if(dp[left][i] != -1) return dp[left][i];

  int ret = solve(left, i+1);
  for(int j=c;j<=d;j++){
    int s = i*j;
    if(s > left) break;
    int tmp = mod_pow(invfac[i], j);
    tmp = (tmp*invfac[j])%MOD;
    tmp = (tmp*solve(left-s, i+1))%MOD;
    //cout << left <<" "<<i <<" " << j << " " << tmp <<endl;
    ret += tmp;
    ret %= MOD;
  }
  return dp[left][i] = ret;
}

 main() {
    cin >> n >> a >> b >> c >> d;

    fac[0] = 1;
    FOR(i,1,1000) fac[i] = (fac[i-1]*i)%MOD;
    REP(i,1001) invfac[i] = inv(fac[i]);

    memset(dp,-1,sizeof dp);
    int ret = solve(n, a)*fac[n];
    ret %= MOD;
    cout << ret ;
    return 0;
}