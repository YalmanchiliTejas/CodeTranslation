#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main() {
        long long k, a, b;
        scanf("%lld%lld%lld", &k, &a, &b);
        long long d = a - b;
        if (d <= 0) {
                if (a >= k) {
                        puts("1");
                        return 0;
                } else {
                        puts("-1");
                        return 0;
                }
        } else {
                long long ans = (k - a + d - 1) / d;
                printf("%lld\n", ans * 2 + 1);
        }
        return 0;
}

