import sys
import numpy as np

readline = sys.stdin.readline
read = sys.stdin.read
MOD = 10**9 + 7

n = int(input())
a = np.array(readline().split(), dtype=np.uint64)
r = np.cumsum(a[::-1])[::-1]
r %= MOD
x = a[:-1] * r[1:]
x %= MOD
ans = np.sum(x) % MOD
print(int(ans))