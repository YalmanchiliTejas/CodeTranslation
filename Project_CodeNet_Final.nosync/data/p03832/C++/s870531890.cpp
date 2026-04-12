#include <bits/stdc++.h>
using namespace std;
constexpr long long gcd(long long a, long long b){return b ? gcd(b, a % b) : a;}
constexpr long long lcm(long long a, long long b){return a / gcd(a, b) * b;}
constexpr int INF = 1e9, MOD = INF + 7, around[] = {0, 1, 1, -1, -1, 0, -1, 1, 0, 0};
constexpr int mod_pow(long long x, long long n, const int mod){long long ret=1;while(n){if(n&1)(ret*=x)%=mod;(x*=x)%=mod;n>>=1;}return ret;}
template<int n> struct Factorial{long long arr[n+1],ary[n+1];constexpr Factorial():arr(),ary(){arr[0]=1;ary[0]=1;for(int i=0;i<n;i++){arr[i+1]=arr[i]*(i+1)%MOD;ary[i+1]=mod_pow(arr[i+1],MOD-2,MOD);}}}; constexpr Factorial<1010> fact;
constexpr long long comb(int a, int b){if(a < b) return 0LL;if(!a or !b) return 1LL; long long pos = fact.arr[a], pot = fact.ary[a - b], por = fact.ary[b]; return pos * pot % MOD * por % MOD;}
constexpr int vx[] = {1, 0, -1, 0}, vy[] = {0, 1, 0, -1};
constexpr long double PI = abs(acos(-1));
constexpr int sqrtN = 512, logN = 32;
constexpr long long LINF=1e18;

int main(){
	long n, a, b, c, d; cin >> n >> a >> b >> c >> d;
	
	long dp[1005] = {}; dp[n] = 1;
	for(int i = a; i <= b; i++){
		for(int k = i * c; k < n + 1; k++){
			long A = k;
			long B = 1;
			
			for(int j = 1; j < d + 1; j++){
				if(k - i * j < 0) break;
				
				(B *= comb(A, i)) %= MOD;
				A -= i;
				
				if(j >= c){
					(dp[k - i * j] += dp[k] * B % MOD * fact.ary[j] % MOD) %= MOD;
				}
			}
		}
	}
	
	cout << dp[0] << endl;
	return 0;
}
