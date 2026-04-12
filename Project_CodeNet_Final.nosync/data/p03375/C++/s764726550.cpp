#include <bits/stdc++.h>
using namespace std;
const int maxn=3005;
int n, mod, s[maxn][maxn], C[maxn][maxn];
int ksm(int u,int v, int m){
	int s = 1;
	for(int i = v; i; i >>= 1){
		if(i & 1) s = 1ll * s * u % m;
		u = 1ll * u * u % m;
	}    
	return s;
}
int main(){
    cin >> n >> mod;
    s[0][0]=1; C[0][0] = 1;
    for(int i = 1; i <= n + 1; i++){
    	C[i][0] = 1; C[i][i] = 1; s[i][i] = 1;
        for(int j = 1; j < i; j++){
            s[i][j] = (s[i - 1][j - 1]+1ll * s[i - 1][j] * j) % mod;
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
    }
    int ans = 0;
    for(int i = 0; i <= n; i++){
        int sum = 0, w = ksm(2, ksm(2, n - i, mod - 1), mod), base = ksm(2, n - i, mod);
        for(int j = 0,coef = 1; j <= i; j++,coef = 1ll * coef * base % mod)
            sum=(sum + 1ll * s[i + 1][j + 1] * w % mod * coef) % mod;
        ans = (ans + (i & 1 ? - 1ll : 1) * C[n][i] * sum) % mod;
    }
    cout<<(ans + mod) % mod << endl;
    return 0;
}