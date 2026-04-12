#include <iostream>
#define llint long long
#define mod 1000000007

using namespace std;

llint h, w, k;

const int FACT_MAX = 400005;
llint fact[FACT_MAX], fact_inv[FACT_MAX];

llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

void make_fact()
{
	llint val = 1;
	fact[0] = 1;
	for(int i = 1; i < FACT_MAX; i++){
		val *= i;
		val %= mod;
		fact[i] = val;
	}
	fact_inv[FACT_MAX-1] = modpow(fact[FACT_MAX-1], mod-2);
	for(int i = FACT_MAX-2; i >= 0; i--){
		fact_inv[i] = fact_inv[i+1] * (i+1) % mod;
	}
}

llint calc(llint h, llint w)
{
  llint ret = 0;
  for(llint i = 1; i <= w-1; i++){
    ret += 2 * i * (w-i) % mod, ret %= mod;
  }
  //cout << ret << endl;
  ret *= h*h%mod, ret %= mod;
  ret *= k*(k-1)/2%mod, ret %= mod;

  //cout << ret << endl;
  for(int i = 0; i < k-2; i++){
    ret *= (h*w-2-i) % mod, ret %= mod;
  }
  //cout << ret << endl;

  ret *= fact_inv[k], ret %= mod;
  return ret;
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  make_fact();

  cin >> h >> w >> k;

  llint ans = calc(h, w) + calc(w, h);
  ans %= mod;
  cout << ans << endl;

  return 0;
}
