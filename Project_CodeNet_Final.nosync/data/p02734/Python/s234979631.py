# -*- coding: utf-8 -*-
import sys 
import numpy as np
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
MOD = 998244353
N, S = map(int, readline().split())
A = list(map(int,readline().split()))
U = 3010
f = np.zeros(U,np.int64)
ans = 0
for a in A:
    f[0] += 1
    f[a:] += f[:-a].copy()
    f %= MOD
    ans += f[S]
ans %= MOD
print(ans)