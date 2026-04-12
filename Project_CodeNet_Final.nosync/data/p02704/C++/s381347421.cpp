    #include <bits/stdc++.h>
     
    using namespace std;
     
    int n;
    short s[510], t[510], a[64][510][510];
    unsigned long long u[510], v[510], ans[510][510], p[510];
    int cntHor[510][64], cntVer[510][64];
    bitset<64> hor[510], ver[510];
     
    void gen(){
    	p[0] = 1;
     
    	for(int i = 1; i < 64; i++) p[i] = p[i - 1] << 1;
    }
     
    void Fail(){
    	cout << "-1\n"; exit(0);
    }
     
    int main(){
    	gen();
    	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    	
    	cin >> n;
     
    	for(int i = 1; i <= n; i++) cin >> s[i];
    	for(int i = 1; i <= n; i++) cin >> t[i];
    	for(int i = 1; i <= n; i++) cin >> u[i];
    	for(int i = 1; i <= n; i++) cin >> v[i];
     
    	for(int k = 0; k < 64; k++){
    		for(int i = 1; i <= n; i++){
    			for(int j = 1; j <= n; j++){
    				if(s[i] == 0){
    					if(u[i] & p[k]) a[k][i][j] = 1;
    				} else {
    					if(u[i] & p[k]);
    					else a[k][i][j] = -1;
    				}
    			}
    		}
    	}
     
    	for(int k = 0; k < 64; k++){
    		for(int j = 1; j <= n; j++){
    			for(int i = 1; i <= n; i++){
    				if(t[j] == 0){
    					if(v[j] & p[k]){
    						if(a[k][i][j] == -1) Fail();
     
    						a[k][i][j] = 1;
    					}
    				} else {
    					if(v[j] & p[k]);
    					else {
    						if(a[k][i][j] == 1) Fail();
    						a[k][i][j] = -1;
    					}
    				}
    			}
    		}
    	}
     
    	for(int k = 0; k < 64; k++){
    		for(int i = 1; i <= n; i++){
    			for(int j = 1; j <= n; j++){
    				if(s[i] == 0 && a[k][i][j] != 1) cntHor[i][k]++;
    				if(t[j] == 0 && a[k][i][j] != 1) cntVer[j][k]++;
     
    				if(a[k][i][j] == 1){
    					if(s[i] == 1) hor[i][k] = true;
    					if(t[j] == 1) ver[j][k] = true;
    				}
    			}
    		}
    	}
     
    	for(int k = 0; k < 64; k++){
    		for(int i = 1; i <= n; i++){
    			for(int j = 1; j <= n; j++){
    				if(a[k][i][j] == 0){
    					if(s[i] == 1 && (t[j] == 1 || cntVer[j][k] > 1) && !hor[i][k]){
    						cntVer[j][k]--;
    						a[k][i][j] = 1;
    						hor[i][k] = true;
    					} else if (t[j] == 1 && (s[i] == 1 || cntHor[i][k] > 1) && !ver[j][k]){
    						cntHor[i][k]--;
    						a[k][i][j] = 1;
    						ver[j][k] = true;
    					}
    				}
     
    				if(a[k][i][j] == 1) ans[i][j] += p[k];
    			}
    		}
    	}
     
    	for(int i = 1; i <= n; i++){
    		unsigned long long x, y;
    		x = ans[i][1], y = ans[i][1];
     
    		for(int j = 1; j <= n; j++){
    			x &= ans[i][j];
    			y |= ans[i][j];
    		}
     
    		if(s[i] == 0 && u[i] != x) Fail();
    		else if (s[i] == 1 && u[i] != y) Fail();
    	}
     
    	for(int j = 1; j <= n; j++){
    		unsigned long long x, y;
    		x = ans[1][j], y = ans[1][j];
     
    		for(int i = 1; i <= n; i++){
    			x &= ans[i][j];
    			y |= ans[i][j];
    		}
     
    		if(t[j] == 0 && v[j] != x) Fail();
    		else if (t[j] == 1 && v[j] != y) Fail();
    	}
     
    	for(int i = 1; i <= n; i++){
    		for(int j = 1; j <= n; j++){
    			cout << ans[i][j] << " \n"[j == n];
    		}
    	}
     
    	return 0;
    }