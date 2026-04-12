#include <bits/stdc++.h>

using namespace std; 

int n, m; 
int S[3005][3005]; 
int C[3005][3005]; 
int pw2m[3005], pw2mm[3005];  


int add(int x, int y) {
    return (x += y) >= m ? x - m : x; 
}

void work() {
    S[0][0] = C[0][0] = 1; 
    for (int i = 1; i <= n + 1; i++) {
        C[i][0] = 1;   
        for (int j = 1; j <= i; j++) {
            S[i][j] = add(S[i - 1][j - 1], 1ll * S[i - 1][j] * j % m); 
            C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]); 
        }
    }
    pw2m[0] = pw2mm[0] = 1; 
    for (int i = 1; i <= n; i++)
        pw2m[i] = 1ll * pw2m[i - 1] * 2 % m, 
        pw2mm[i] = 1ll * pw2mm[i - 1] * 2 % (m - 1);  
}

int fpw(int x, int k, int p) {
    int ret = 1; 
    while (k) {
        if (k & 1) ret = 1ll * ret * x % p; 
        x = 1ll * x * x % p; k >>= 1; 
    }
    return ret; 
}

int main() {
    cin >> n >> m;
    work(); 
    int ans = 0;  
    for (int i = 0; i <= n; i++) {
        int pig = 0; 
        for (int j = 0; j <= i; j++) {
            int t1 = fpw(2, pw2mm[n - i], m);
            int t2 = fpw(pw2m[n - i], j, m);  
            pig = add(pig, 1ll * S[i + 1][j + 1] % m * t1 % m * t2 % m); 
        }
        ans = add(ans, 1ll * pig * C[n][i] % m * ((i & 1) ? m - 1 : 1) % m); 
    }
    cout << ans << '\n'; 
    return 0; 
}