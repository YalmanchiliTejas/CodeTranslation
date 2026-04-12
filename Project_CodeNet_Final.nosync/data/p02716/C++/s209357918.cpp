#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define P pair<int, int>
#define F first
//#define S second
#define mod 1000000007
#define MOD 998244353
#define INF 40000000000000000
int dx8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy8[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dx4[4] = {-1, 0, 1, 0};
int dy4[4] = {0, -1, 0, 1};
template <class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int mod_pow(int x, int n, int mm) {
    int res = 1;
    while(n > 0) {
        if(n & 1) res = res * x % mm;
        x = x * x % mm;
        n >>= 1;
    }
    return res;
}
int extgcd(int a, int b, int &x, int &y) {
    int d = a;
    if(b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1;
        y = 0;
    }
    return d;
}
int mod_inverse(int a, int mm) {
    int x, y;
    extgcd(a, mm, x, y);
    return (mm + x % mm) % mm;
}
signed main() {
    int N;
    cin >> N;
    int A[N];
    rep(i, N) cin >> A[i];
    if(N % 2 == 0) {
        vector<vector<int>> dp(2, vector<int>(N, -INF));
        dp[0][0] = A[0];
        dp[1][1] = A[1];
        for(int i = 1; i < N; i++) {
            if(i > 1) chmax(dp[0][i], dp[0][i - 2] + A[i]);
            if(i > 1) chmax(dp[1][i], dp[1][i - 2] + A[i]);
            if(i > 2) chmax(dp[1][i], dp[0][i - 3] + A[i]);
            chmax(dp[1][i], dp[0][i - 1]);
        }
        cout << max(dp[1][N - 1], dp[0][N - 1]) << endl;

    } else {
        vector<vector<int>> dp(3, vector<int>(N, -INF));
        dp[0][0] = A[0];
        dp[1][1] = A[1];
        dp[2][2] = A[2];
        for(int i = 1; i < N; i++) {
            if(i > 1) chmax(dp[0][i], dp[0][i - 2] + A[i]);
            if(i > 1) chmax(dp[1][i], dp[1][i - 2] + A[i]);
            if(i > 2) chmax(dp[1][i], dp[0][i - 3] + A[i]);
            chmax(dp[1][i], dp[0][i - 1]);
            if(i > 1) chmax(dp[2][i], dp[2][i - 2] + A[i]);
            if(i > 2) chmax(dp[2][i], dp[1][i - 3] + A[i]);
            if(i > 3) chmax(dp[2][i], dp[0][i - 3] + A[i]);
            chmax(dp[2][i], dp[1][i - 1]);
        }
        cout << max(dp[0][N - 1], max(dp[1][N - 1], dp[2][N - 1]));
    }
}
