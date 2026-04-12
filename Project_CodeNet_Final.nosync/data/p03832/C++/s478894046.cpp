#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

const int N = 1005;
const int MOD = 1e9+7;
int n, a, b, c, d;
lli fact[N];
lli invFact[N];
lli dpt[N][N]; //first index is size of a group, second is num of people "used"

int inv(int a);

void initFact() {
	fact[0]=fact[1] = 1;
	invFact[0]=invFact[1] = 1;
	for(int i = 2; i < N; i++) {
		fact[i]=i*fact[i-1];
		fact[i] %= MOD;
		invFact[i] = inv(fact[i]);
	}
}

int powe(int a, int b) {
	if(b < 2) return b? a:1;
	else {
		lli base = powe(a, b/2);
		lli ans = base*base; ans %= MOD;
		if(b%2) {ans *= a; ans %=MOD;}
		return ans;
	}
}

int inv(int a) {
	return powe(a, MOD-2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	initFact();

	cin >> n >> a >> b >> c >> d;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) dpt[i][j] = 0;
	dpt[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		if(i < a || i > b)
			for(int j = 0; j <= n; j++) {
				dpt[i][j]=dpt[i-1][j];
			}
		else {
			//How many groups of size i to add?
			//Add none
			for(int j = 0; j <= n; j++) {
				dpt[i][j]=dpt[i-1][j];
			}
			
			//Add k of them
			for(int k = c; k <= d && i*k <= n; k++) {
				for(int j = 0; i*k + j <= n; j++) {
					//Multiplier should be (n-j)!/((i!)^k k! (n-j-i*k)!)
					lli multiplier = fact[n-j];
					multiplier *= inv(powe(fact[i], k));
					multiplier %= MOD;
					multiplier *= invFact[k];
					multiplier %= MOD;
					multiplier *= invFact[n-j-i*k];
					multiplier %= MOD;
					dpt[i][i*k+j] += multiplier*dpt[i-1][j];
					dpt[i][i*k+j] %= MOD;
				}
			}
		}
	}

	cout << dpt[n][n] << endl;
	

	return 0;
}