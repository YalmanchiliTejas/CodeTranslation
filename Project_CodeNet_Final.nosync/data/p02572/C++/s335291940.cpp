#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const long long int mo = 1e9 + 7;
int main(){
    long long int ans = 0, sum = 0;
    long long int a;
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a);
        ans = (ans + sum * a % mo) % mo;
        sum = (sum + a) % mo;
    }
    printf("%lld", ans % mo);
    return 0;
}