#include <bits/stdc++.h>
using namespace std;

inline long long read(){
    long long s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9'){
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9'){
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * w;
}

const long long mo = 1000000007;
long long n, a[333333], sum, ans;

int main(){
    n = read();
    for (int i = 1; i <= n; i++){
        a[i] = read() % mo;
        ans = (ans + (a[i] * sum) % mo) % mo;
        sum = (sum + a[i]) % mo;
    }
    printf("%llu\n", ans);
    return 0;
}