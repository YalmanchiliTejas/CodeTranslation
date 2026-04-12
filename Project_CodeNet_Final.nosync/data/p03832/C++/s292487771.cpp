#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
//const int INF = 1e8;
using namespace std;

typedef long long ull;
const ull M = 1000000007;

ull nCr[1005][1005];
void Pascals(){
	nCr[0][0] = 1;
	range(i,1,1001){
		rep(j,i + 1){
			if(j == 0) nCr[i][j] = nCr[i - 1][j];
			else if(j == i) nCr[i][j] = nCr[i - 1][j - 1];
			else nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]);
			nCr[i][j] %= M;
		}
	}
}

//べき乗 x^n mod M
ull power(ull x, ull n){
	ull res = 1;
	if(n > 0){
		res = power(x, n / 2);
		if(n % 2 == 0) res = (res * res) % M;
		else res = (((res * res) % M) * x ) % M;
	}
	return res;
}

//階乗
ull fact[1005];
ull factorial(ull n, ull r){
	ull res = 1;
	range(i,r,n + 1){
		res*= i;
		res%= M;
		fact[i] = res;
	}
	return res;
}


//完全順列（a[i] != iとなるような順列）の数を返す
ull derangement(ull n /*長さ*/){
	ull dp[1000000] = {0};
	dp[2] = 1;
	range(i,3,n + 1){
		dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
		dp[i] %= M;
	}
	return dp[n];
}

int main(){
	Pascals();
	factorial(1000,1);
	ull fact_rev[1005];
	rep(i,1001) fact_rev[i] = power(fact[i], M - 2);

	long long n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;

	long long dp[1005] = {0};
	dp[n] = 1;
	//rep(i,1005) dp[i] = 1;
	range(i,a,b + 1){
		range(k,i * c,n + 1){
			long long person = k;
			long long comb = 1;

			range(j,1,d + 1){
				long long join = i * j;
				if(k - join < 0) break;

				(comb *= nCr[person][i]) %= M;
				person-=i;

				if(j >= c){
					assert(person >= 0);
					//cout <<k << ' ' <<  i << ' ' << j << endl;
					(dp[k - join] += dp[k] * comb % M * fact_rev[j] % M) %= M;
					//next[k - join] += dp[k] * comb  / fact[j];
				}
					//rep(i,n + 1){ cout << next[i] << ' '; } cout << endl;
			}
		}
		//rep(i,1005) (dp[i] += next[i]) %= M;
		//memset(next, 0, sizeof(next));
	}
	//rep(i,n + 1){ cout << dp[i] << ' '; } cout << endl;

	cout << dp[0] << endl;
}
