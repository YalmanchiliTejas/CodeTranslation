    /* - - - - - - - - - - - - - - -
    	User : 		VanishD
    	problem :
    	Points : 	
    - - - - - - - - - - - - - - - */
    # include <bits/stdc++.h>
    # define 	ll 		long long
    using namespace std;
    const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
    const ll  infll = 0x3f3f3f3f3f3f3f3fll, INFll = 0x7fffffffffffffffll;
    int read(){
    	int tmp = 0, fh = 1; char ch = getchar();
    	while (ch < '0' || ch > '9'){ if (ch == '-') fh = -1; ch = getchar(); }
    	while (ch >= '0' && ch <= '9'){ tmp = tmp * 10 + ch - '0'; ch = getchar(); }
    	return tmp * fh;
    }
    const int P = 1e9 + 7, N = 210;
    int n, h[N];
    ll f[N][2][2][2], g0[2][2][2], g1[2][2][2], use[N];
    ll power(ll x, int y){
    	ll i = x; x = 1;
    	while (y > 0){
    		if (y % 2 == 1) x = x * i % P;
    		i = i * i % P;
    		y /= 2;
    	}
    	return x;
    }
    int main(){
    //	freopen(".in", "r", stdin);
    //	freopen(".out", "w", stdout);
    	n = read();
    	for (int i = 1; i <= n; i++) h[i] = read(); 
    	h[++n] = 1;
    	int las = inf, lim, tmp, cnt = 0;
    	while (cnt < n){
    		lim = -1;
    		for (int j = 1; j <= n; j++)
    			if (use[j] == 0) 
    				lim = max(h[j], lim);
    		tmp = las - lim;
    		for (int j = 1; j <= n; j++){
    			if (use[j] == 2) continue;
    			if (use[j] == 0){
    				if (h[j] < lim) continue;
    				use[j] = 1;
    				f[j][0][0][0] = f[j][0][1][1] = 1;
    				cnt++;
    			}
    			else if (use[j] == 1){
    				f[j][0][0][0] = f[j][0][1][1] = (f[j][0][1][1] + f[j][0][0][0]) * power(2, tmp - 1) % P;
    				f[j][0][0][1] = f[j][0][1][0] = (f[j][0][0][1] + f[j][0][1][0]) * power(2, tmp - 1) % P;
    				if (tmp % 2 == 1){
    					swap(f[j][1][0][0], f[j][1][1][1]);
    					swap(f[j][1][0][1], f[j][1][1][0]);
    				}
    			}
    			if (j != 1 && use[j - 1] != 0){
    				use[j] = 2;
    				int k = j - 1;
    				while (use[k] == 2) k--;
    				for (int t0 = 0; t0 <= 1; t0++)
    					for (int t1 = 0; t1 <= 1; t1++)
    						for (int t2 = 0; t2 <= 1; t2++)
    							g0[t0][t1][t2] = f[k][t0][t1][t2], g1[t0][t1][t2] = f[j][t0][t1][t2];
    				for (int t0 = 0; t0 <= 1; t0++)
    					for (int t1 = 0; t1 <= 1; t1++){
    						f[k][0][t0][t1] = (g0[0][t0][1] * g1[0][0][t1] + g0[0][t0][0] * g1[0][1][t1]) % P;
    						f[k][1][t0][t1] = ((g0[1][t0][1] + g0[1][t0][0]) * (g1[1][0][t1] + g1[1][1][t1] + g1[0][0][t1] + g1[0][1][t1])) % P;
    						f[k][1][t0][t1] = (f[k][1][t0][t1] + (g0[0][t0][1] + g0[0][t0][0]) * (g1[1][0][t1] + g1[1][1][t1])) % P;
    						f[k][1][t0][t1] = (f[k][1][t0][t1] + g0[0][t0][1] * g1[0][1][t1] + g0[0][t0][0] * g1[0][0][t1]) % P;
    					}
    			}
    		}
    		las = lim; 
    	}
    	ll ans = 0;
    	for (int t0 = 0; t0 <= 1; t0++)
    		for (int t1 = 0; t1 <= 1; t1++)
    			ans = (ans + f[1][0][t0][t1] + f[1][1][t0][t1]) % P;
    	printf("%lld\n", 1ll * ans * power(2, P - 2) % P);
    	return 0;
    }