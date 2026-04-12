#include<bits/stdc++.h>
using namespace std;

long long dp[3005][3005];

int main()
{
int n;
cin>>n;
vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
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
printf("%lld",dp[0][n-1]);
}