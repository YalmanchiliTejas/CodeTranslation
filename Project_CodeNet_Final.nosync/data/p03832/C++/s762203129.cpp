/**/
#include <bits/stdc++.h>
using namespace std;
/***********************************************/
/* Dear online judge:
 * I've read the problem, and tried to solve it.
 * Even if you don't accept my solution, you should respect my effort.
 * I hope my code compiles and gets accepted.
 *  ___  __     _______    _______      
 * |\  \|\  \  |\  ___ \  |\  ___ \     
 * \ \  \/  /|_\ \   __/| \ \   __/|    
 *  \ \   ___  \\ \  \_|/__\ \  \_|/__  
 *   \ \  \\ \  \\ \  \_|\ \\ \  \_|\ \ 
 *    \ \__\\ \__\\ \_______\\ \_______\
 *     \|__| \|__| \|_______| \|_______|
 */
const long long mod = 1000000007;

long long fact[1010],inv[1010];
long long dp[1010][1010];

int A,B;
int C,D;
int N;

long long pow_mod(long long base,long long power) {
	long long res = 1;
	while(power) {
		if(power&1)
			res = res * base % mod;
		base = base * base % mod;
		power >>= 1;
	}
	return res;
}

long long calc(int N,int G,int i) {
	long long ncri = fact[N];
	ncri = ncri *  pow_mod(inv[G],i) % mod;
	ncri = ncri * inv[i] % mod;
	ncri = ncri * inv[N - i * G] % mod;
	return ncri;
}

long long bt(int G,int N) {
	if(N == 0)
		return 1;
	if(G > B || N < G)
		return 0;
	long long & ref = dp[G][N];
	if(ref != -1)
		return ref;
	ref = bt(G+1,N);
	for(int i = C;i <= D && i * G <= N;i++) {
		ref = (ref + calc(N,G,i) * bt(G+1,N - i * G)) % mod;
	}
	return ref;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	fact[0] = fact[1] = inv[0] = inv[1] = 1;
	for(int i = 2;i < 1010;i++) {
		fact[i] = fact[i-1] * i % mod,inv[i] = pow_mod(fact[i],mod-2);
	}
	
	memset(dp,-1,sizeof dp);
	cin>>N>>A>>B>>C>>D;
	cout<<bt(A,N)<<'\n';
	return 0;
}
/**/
