#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;


const int mod = 1000000000 + 7;
// 以下コピー
const int MAX_FACT = 2000000;

ll fact[MAX_FACT];

ll pow_mod(ll a,ll n){
  ll cur=1;
  ll mul=a;
  while(n){
    if(n%2)cur=(cur*mul)%mod;
    mul=(mul*mul)%mod;
    n/=2;
  }
  return cur;
}

ll div_mod(int a){
  return pow_mod(a,mod-2);
}

// factを前計算
void calcFact(){
  fact[0]=1;
  for(int i=1;i<MAX_FACT;i++)
    fact[i]=(fact[i-1]*i)%mod;
}

// [a, a +1, a +2, .., b] の和
ll sums(ll a, ll b){
    if(a > b) return 0;
    else if(a == b) return a;
    ll ans = 0;
    ans += b * (b + 1) /2;
    ans -= (a - 1) * a / 2;
    return ans;
}

// aCbのmodを計算
// 計算量はO(log(fact[a])+log(fact[a-b]))程度
ll comb(ll a,ll b){
  if(a<0||b<0)return 0;
  else if(a<b)return 0;
  else if(b==0)return 1;
  else if(a == 0)return 1;
  ll res=fact[a];
  res=(res*div_mod(fact[b]))%mod;
  res=(res*div_mod(fact[a-b]))%mod;
  return res;
}

// aCbを計算
// aとbがおおきくても、a%modとb%modが小さければ計算できる
// a%modとb%modはfact tableに前計算しておく必要あり
ll comb_large(ll a, ll b){
  ll res = 1;
  ll tmp_a = a;
  ll tmp_b = b;
  while(!(tmp_a==0&&tmp_b==0)){
    const ll aa = tmp_a % mod;
    const ll bb = tmp_b % mod;
    res = (res * comb(aa,bb)) %mod;
    tmp_a /= mod;
    tmp_b /= mod;
  }
  return res;
}


ll H, W, K;


int main(){

    calcFact();
    cin >> H >> W >> K;
    ll ans = 0;
    ll cons = comb(H * W - 2, K - 2);

    for(int i = 0; i < W; i++){
        // [1, i] までがx2
        // のこりが普通に足すだけ
        ll tmp = (sums(1, min((ll)i, W - i - 1)) * 2 + sums(min((ll)i, W - i - 1) + 1, max((ll)i, W - i - 1))) % mod;
        (tmp *= H) %= mod;
        (tmp *= H) %= mod;
        (ans += (tmp) % mod) %= mod;
    }

    // cout << ans << endl;

    for(int i = 0; i < H; i++){
        // [1, i] までがx2
        // のこりが普通に足すだけ
        ll tmp = (sums(1, min((ll)i, H - i - 1)) * 2 + sums(min((ll)i, H - i - 1) + 1, max((ll)i, H - i - 1))) % mod;
        // ll tmp = (sums(1, min((ll)i, H - i - 1)) * 2 + sums(i + 1, max((ll)i, H - i - 1))) % mod;
        (tmp *= W) %= mod;
        (tmp *= W) %= mod;
        (ans += (tmp) % mod) %= mod;
        // (ans += (tmp * W) % mod) %= mod;
    }

    // cout << ans << endl;

    
    (ans *= cons) %= mod;
    (ans *= div_mod(2)) %= mod;
    cout << ans << endl;

    return 0;
}
