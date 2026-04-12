//
// Created by bytedance on 2020/4/10.
//


#include <bits/stdc++.h>
//#include <fstream>

using namespace std;
const int maxn = 1e5 + 5;
int sum[maxn];

int main() {
    memset(sum, -1, sizeof(sum));
    long long n;
    int x, m;
    scanf("%lld%d%d", &n, &x, &m);
    int cnt = 1;
    long long ans = 0;
    while (cnt <= n) {
        if (sum[x] != -1) {
            long long tans = x;
            int tmp = 1LL * x * x % m;
            while (tmp != x) {
                tans += tmp;
                tmp = 1LL * tmp * tmp % m;
//                printf("%d %d\n", tmp, x);
            }
            ans += tans * ((n - cnt) / (cnt - sum[x]));
            n = (n - cnt) % (cnt - sum[x]) + 1;
            while (n) {
                ans += x;
                n--;
                x = 1LL * x * x % m;
            }
            break;
        }
        sum[x] = cnt++;
        ans += x;
        x = 1LL * x * x % m;
    }
    printf("%lld\n", ans);
    return 0;
}