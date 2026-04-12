#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

const int mod = 998244353;

int add(int i, int j) { return ((i += j) < mod ? i : i -= mod); }
int mult(int i, int j) { return (ll) i * j % mod; }

int A[3000];

int k;
int dp[3000][3001];

int f(int i, int j) {
    if(j < 0) return 0;
    if(j == 0) return i + 2;
    if(i < 0) return 0;
    if(dp[i][j] > -1) return dp[i][j];
    int mx = f(i - 1, j);
    mx = add(mx, f(i - 1, j - A[i]));
    
    return dp[i][j] = mx;
}

int main() {
    int n; cin >> n >> k;
    memset(dp, -1, sizeof dp);
    
    for(int i = 0; i < n; ++i)
        cin >> A[i];
    int mx = 0;
    for(int i = 0; i < n; ++i)
        mx = add(mx, f(i, k));
    
    cout << mx;
    
    return 0;
}