#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

bool dt[200000][3];
ll dp[200000][3];
int n;
ll A[200000];

ll f(int i, int j) {
    if(i >= n) return (n & 1) * (j ? 0 : -1e10);
    if(dt[i][j]) return dp[i][j];
    dt[i][j] = 1;
    if(j == 2) return dp[i][j] = A[i] + f(i + 2, 2);
    return dp[i][j] = max(A[i] + f(i + 2, j), f(i + 1, j + 1));
}

int main() {
    cin >> n;
    memset(dt, 0, sizeof dt);
    for(int i = 0; i < n; ++i)
        cin >> A[i];
        
    cout << f(0, n % 2 == 0);
    
    return 0;
}