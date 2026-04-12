#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define F first
#define S second
#define eb emplace_back
using ll = long long;

const int nax = 3005;
lli dp[nax][nax];

int main() {
    //freopen("input.txt","r",stdin);
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    // dp[0][n-1]
    for(int L = n - 1; L >= 0; --L) {
        for(int R = L; R < n; ++R) {
            if(L == R) {
                dp[L][R] = a[L];
            }
            else {
                dp[L][R] = max(a[L] - dp[L+1][R], a[R] - dp[L][R-1]);
            }
        }
    }
    printf("%lld\n", dp[0][n-1]);
}
