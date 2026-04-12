#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 7;
const int mod = 1e9 + 7;

int h[maxn];

long long power(int x, int times) { 
    long long rt = 1, base = x;
    while (times) {
        if (times & 1) rt = rt * base % mod;
        base = base * base % mod;
        times >>= 1;
    }
    return rt;
}

int dp1(int x, int y, int level) {
    static bool vis[maxn][maxn];
    static int f[maxn][maxn];
    if (vis[x][y]) return f[x][y];
    vis[x][y] = true;

    int MIN = h[x];

    long long cnt1 = 1;
    for (int i = x; i <= y; i++) {
        MIN = min(MIN, h[i]);
    }

    for (int i = x; i <= y; i++) 
        if (h[i] != MIN) {
            int j = i;
            while (j <= y && h[j] != MIN) j++;
            j--;
            cnt1 = cnt1 * dp1(i, j, MIN) % mod;
            i = j;
        }
    cnt1 = cnt1 * power(2, MIN - level) % mod;
    //cout << x << ' ' << y << ' ' << level << ' ' << cnt1 << endl;
    return f[x][y] = cnt1;
}

int dp2(int x, int y, int level) {
    static bool vis[maxn][maxn];
    static int f[maxn][maxn];
    if (vis[x][y]) return f[x][y];
    vis[x][y] = true;

    int MIN = h[x], k = 0;

    long long cnt1 = 1, cnt2 = 1;
    for (int i = x; i <= y; i++) {
        MIN = min(MIN, h[i]);
    }

    for (int i = x; i <= y; i++) 
        if (h[i] != MIN) {
            int j = i;
            while (j <= y && h[j] != MIN) j++;
            j--;
            cnt1 = cnt1 * dp1(i, j, MIN) % mod;
            cnt2 = cnt2 * (dp1(i, j, MIN) + dp2(i, j, MIN)) % mod;
            i = j;
        }
        else {
            k++;
        }
    // cout << cnt1 << ' ' << cnt2 << endl;
    int &rt = f[x][y];
    rt = ((cnt2 * power(2, k) % mod + cnt1 * (power(2, MIN - level) - 2) % mod) % mod + mod) % mod;
    // cout << cnt1 * (power(2, MIN - level) - 2) % mod << endl;
    // cout << cnt2 * power(2, k) % mod << endl;
    // cout << endl;
    
    // cout << x << ' ' << y << ' ' << level << ' ' << rt << endl;
    // cout << cnt1 << ' ' << cnt2 << ' ' << k << ' ' << MIN << endl;   
    return rt;
}

int main() {
    int n;
    scanf("%d", &n);
    

    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
    }

    cout << dp2(1, n, 0) << endl;
    return 0;
}