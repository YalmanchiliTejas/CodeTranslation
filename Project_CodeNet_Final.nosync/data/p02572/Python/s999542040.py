n = int(input())
mod = 10 ** 9 + 7
import numpy as np
a = list(map(int, input().split()))
s=0
ss=0
for i in range(n):
    if i > 0:
        ss += a[i-1]%mod
    s += ss * a[i] % mod
print(s%mod)
