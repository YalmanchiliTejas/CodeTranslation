import sys
readline = sys.stdin.readline
readlines = sys.stdin.readlines

import numpy as np

MOD = 10**9 + 7

N = int(readline())
H = [int(x) for x in readline().split()]

# 「初の同色」の位置によって場合分け。座圧して、近い区間のものは和をまとめて持つようにする。

H_unique = sorted(set([0,1]+H))
H_to_I = {h:i for i,h in enumerate(H_unique)}

items = [0] + [y-x for x,y in zip(H_unique,H_unique[1:])]

inv = pow(2,MOD-2,MOD)
coef = np.array([(pow(2,x+1,MOD)-2) * pow(inv,h,MOD) % MOD for x,h in zip(items,H_unique)],np.int64)

dp = np.zeros(len(H_unique),np.int64)
dp[0] = 1
I1,H1 = 1,1
for H2 in H:
    I2 = H_to_I[H2]
    prev = dp
    dp = np.zeros_like(prev)
    if I1 < I2:
        dp[0] = 2*prev[0]
        dp[1:I1+1] = prev[1:I1+1] * pow(2,H2-H1,MOD)
        dp[I1+1:I2+1] = coef[I1+1:I2+1] * pow(2,H2,MOD) % MOD * prev[0] % MOD
    else:
        prev[0] += prev[I2+1:].sum()
        dp += prev
        dp[0] *= 2
        dp[I2+1:] = 0
    dp %= MOD
    I1,H1 = I2,H2

answer = dp.sum()%MOD
print(answer)