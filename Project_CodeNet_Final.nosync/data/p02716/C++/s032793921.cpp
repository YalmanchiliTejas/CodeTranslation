#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n = 200005;
int n, a[max_n];
ll dp[max_n];
ll sum[max_n];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a+i);
    sum[1] = a[1];
    for(int i = 2; i <= n; i++) {
        sum[i] = sum[i-2] + a[i]; 
    }
    for(int i = 2; i <= n; i++) {
        if(i&1) {
            dp[i] = max(dp[i-1], dp[i-2] + a[i]);
        }
        else {
            dp[i] = max(sum[i-1], a[i] + dp[i-2]);
        }
    }
    printf("%lld\n", dp[n]);
    return 0;
}