#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
using tpl = tuple<int, int, int>;
typedef pair<int,int> pii;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

const int mod = 1000000000 + 7;
int N, A, B, C, D;

const int MAX_ARG=1100;
// 組み合わせを求める公式
ll dp_comb[MAX_ARG][MAX_ARG];
ll comb(int a,int b){
  if(a<0||b<0)return 0;
  if(a<b)return 0;
  else if(b==0)return 1;
  else if(dp_comb[a][b]>=0)return dp_comb[a][b];
  return dp_comb[a][b]=(comb(a-1,b)+comb(a-1,b-1))%mod;
}

// O(logn)で繰り返し二乗法によりnum^p%modを計算
ll mod_pow(ll num,ll p,ll mod){
  ll mul=num;
  ll res=1;
  while(p){
    if(p%2)res=(res*mul)%mod;
    p/=2;
    mul=(mul*mul)%mod;
  }
  return res;
}
// fermerの小定理を用いてmodの割算を計算
ll div_mod(ll num,ll mod){
  return mod_pow(num,mod-2,mod);
}


ll dp[1010][1010];
ll rec(int n, int size){
    if(dp[n][size] >= 0) return dp[n][size];
    ll res = 0;
    if(size > B){
        res = (n == 0);
    }
    else{
        (res += rec(n, size + 1)) %= mod;
        ll c = 1;
        ll p = 1;
        for(int i = 1; i <= D && n - i * size >= 0; i++){
            (p *= i) %= mod;
            (c *= comb(n - (i - 1) * size, size)) %= mod;
            if(i >= C){
                ll pinv = div_mod(p, mod);
                ll tmp = (pinv * c) % mod;
                (res += tmp * rec(n - i * size, size + 1)) %= mod;
            }
        }
    }
    return dp[n][size] = res;
}

int main(){

    fastStream();
    cin >> N >> A >> B >> C >> D;
    memset(dp_comb, -1, sizeof(dp_comb));
    memset(dp, -1, sizeof(dp));
    cout << rec(N, A) << endl;

    return 0;
}
