#include <bits/stdc++.h>

using namespace std;

long long dp[3003][3003];
bool done[3003][3003];
long long A[3003];

long long f(int a, int b) {
    if (a > b)  return 0;
    if (done[a][b]) return dp[a][b];
    done[a][b] = true;

    long long ans = 0;
    ans = A[a] - f(a+1, b);
    ans = max(ans, A[b] - f(a, b-1));    

    // if (turn == 1)  ans *= -1;  
    dp[a][b] = ans;
    return ans;
}


int main(void) {

    int n;
    cin>>n;
    for(int i = 0; i < n; ++i) {
        cin>>A[i];
    }
    memset(done, 0, sizeof(done));
    cout<<f(0, n-1);

    return 0;
}

