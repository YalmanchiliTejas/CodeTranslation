#!/usr/bin/env python3
n, *a = map(int, open(0).read().split())
s = ans = 0
MOD = 10**9+7
for b, c in zip(a, a[1:]):
    s = (s + (b % MOD)) % MOD
    ans = (ans + s * (c % MOD) % MOD) % MOD
print(ans)