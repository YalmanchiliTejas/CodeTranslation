#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4 + 10, M = 100, MOD = 1e9 + 7;

string str;
int n, mod, ch[N], pos[N][M];

signed main() {
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> str >> mod;
    n = str.size();
    
    for(int i = 0; i < n; i++)
        ch[i] = str[i] - '0';
    
    pos[0][0] = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < mod; j++)
            for(int k = 0; k < 10; k++) {
                pos[i+1][(j + k) % mod] += pos[i][j];
                pos[i+1][(j + k) % mod] %= MOD;
            }
    int sum = 0, t = 0;
    for(int i = 0; i < n; i++) {
        int i2 = n - i - 1;
        for(int j = 0; j < ch[i]; j++, t++) {
            t %= mod;
            sum += pos[i2][(mod - t) % mod];
            sum %= MOD;
        }
        t %= mod;
    }
    if(t % mod == 0)
        sum++;
    cout << (sum-1 + MOD) % MOD;
}