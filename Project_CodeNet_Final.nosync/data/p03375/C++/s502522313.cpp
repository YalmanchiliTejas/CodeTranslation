#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
using tpl = tuple<int, int, int>;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

const int MAX_FACT = 2000000;
ll fact[MAX_FACT];

ll M;

ll pow_mod(ll a,ll n){
  ll cur=1;
  ll mul=a;
  while(n){
    if(n%2)cur=(cur*mul)%M;
    mul=(mul*mul)%M;
    n/=2;
  }
  return cur;
}

ll div_mod(int a){
  return pow_mod(a,M-2);
}

// factを前計算
void calcFact(){
  fact[0]=1;
  for(int i=1;i<MAX_FACT;i++)
    fact[i]=(fact[i-1]*i)%M;
}

// aCbのmodを計算
// 計算量はO(log(fact[a])+log(fact[a-b]))程度
ll comb(ll a,ll b){
  if(a<0||b<0)return 0;
  else if(a<b)return 0;
  else if(b==0)return 1;
  ll res=fact[a];
  res=(res*div_mod(fact[b]))%M;
  res=(res*div_mod(fact[a-b]))%M;
  return res;
}

int N;

// dp[j][i] = j杯のラーメンに、iまでの具材を1つ以下分割してのせる場合の個数
ll dp[3010][3010];
ll rec(int j, int i){
    if(dp[j][i] >= 0) return dp[j][i];
    if(j == 0) return 1;
    if(j == i) return 1;
    ll res = (rec(j-1, i-1) + (rec(j, i-1) * (j + 1)) % M) % M;
    return dp[j][i] = res;
}

ll pow2[10000100];
// powpow2[i] = 2^(2^i)
ll powpow2[10100];

int main(){

    cin >> N >> M;
    calcFact();

    memset(dp, -1, sizeof(dp));

    pow2[0] = 1;
    for(int i = 1; i < 10000010; i++)
        pow2[i] = (pow2[i - 1] * 2) % M;

    powpow2[0] = 2;
    for(int i = 1; i < 10100; i++)
        powpow2[i] = (powpow2[i-1] * powpow2[i-1]) % M;

    int sign = 1;
    ll tot = 0;
    for(int i = 0; i <= N; i++){
        ll way = 0;
        for(int j = 0; j <= i; j++){
             // cout << j << "," << i << "," << rec(j, i) << endl;
            ll tmp = (((rec(j, i) * powpow2[N - i]) % M) * pow2[(N-i)*j]) % M;
            way = (way + tmp) % M;
        }
        tot += sign * ((way * comb(N, i)) % M);
        if(tot < M) tot += M;
        tot %= M;
        sign *= -1;
    }
    cout << tot << endl;

    return 0;
}
