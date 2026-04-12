#include <bits/stdc++.h>
#define int long long
#define pp pair<int,int>
#define ff first
#define dd second
#define pb push_back
#define N 3003
using namespace std;

int n, m;

int binn[N][N];
int stirr[N][N];

int p2[N];
int pp2[N];

unordered_map<int,int> powxx;

int binomialOwn(int n ,int k) {
    if(k > n) return 0;
    if(k == n) return 1;
    if(k == 0) return 1;
    if(binn[n][k] != -1) return binn[n][k];
    binn[n][k] = (binomialOwn(n-1,k) + binomialOwn(n-1,k-1)) % m;
    return binn[n][k];
}

int stirlingOwn(int n, int k) {
    if(k > n) return 0;
    if(k == n) return 1;
    if(k == 0) return 0;
    if(k == 1) return 1;
    if(stirr[n][k] != -1) return stirr[n][k];
    stirr[n][k] = (stirlingOwn(n-1,k-1) + k*stirlingOwn(n-1,k) % m) % m;
    return stirr[n][k];
}

int pow2(int x) {
    if(x == 0) return 1; if(x == 1) return 2;
    if(x & 1) return 2*pow2(x-1) % m;
    int k = pow2(x/2);
    return k*k%m;
}

// i = 2, j = 0
int ways2(int i, int j) {
    int res = (stirlingOwn(i,j+1)*(j+1) + stirlingOwn(i,j)) % m;
    //cout << res << " res\n";
    res *= pow2((n-i)*j);
    res %= m;
    res *= pp2[n-i];
    return (res % m);
}

int ways(int i) {
    int res = 0;
    for(int x = 0; x <= i; ++x) {
        res += ways2(i,x);
    }
    return (res % m);
}

main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    p2[0] = 1; pp2[0] = 2;
    for(int i = 1; i  < N; ++i) {
        p2[i] = p2[i-1]*2 % m;
        pp2[i] = pp2[i-1]*pp2[i-1]%m;
    }
    for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) { binn[i][j] = stirr[i][j] = -1; }
    int ans = 0;
    for(int i = 0; i <= n; ++i) {
        int temp = binomialOwn(n, i) * ways(i) % m;
        if (i & 1) {
            ans = ans + m - temp;
        } else {
            ans = ans + temp;
        }
    }
    cout << (ans % m) << "\n";
}
