#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int A[3000];
ll dp[3000][3000];
bool rd[3000][3000];

ll f(int i, int j) {
    if(i == j) return A[i];
    if(rd[i][j]) return dp[i][j];
    rd[i][j] = 1;
    return dp[i][j] = max(A[i] - f(i + 1, j), A[j] - f(i, j - 1));
    
}

int main() {
    int n; cin >> n;
    
    for(int i = 0; i < n; ++i)
        cin >> A[i];
        
    cout << f(0, n - 1);
    return 0;
}