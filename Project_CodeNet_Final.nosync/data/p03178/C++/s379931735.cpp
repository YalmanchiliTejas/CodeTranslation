#include<bits/stdc++.h>
#define maxd 120
#define maxn 120000
using namespace std;
const int mod = 1000000007;
char s[maxn];
int K[maxn];
int f[maxn][maxd];
int main(){
	int D;
	cin >> s + 1 >> D;
	int n = strlen(s + 1);
	for(int i = 1; i <= n; i += 1) K[i] = s[i] - '0';
	int sum = 0;
	f[0][0] = 1;
	for(int i = 1; i <= n; i += 1){
		for(int j = 0; j < D; j += 1)
			for(int k = 0; k < 10; k += 1)
				f[i][j] = (f[i][j] + f[i - 1][(j + 10 * D - k) % D]) % mod;
		for(int k = K[i] + 1; k < 10; k += 1)
			f[i][(sum + k) % D] = (f[i][(sum + k) % D] + mod - 1) % mod;
		sum = (sum + K[i]) % D;
		
	}
	cout << (f[n][0] + mod - 1) % mod;
}