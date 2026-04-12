import sys
from math import log10, floor
K = input()
d = int(input())
digit_num = len(K)
MOD = 10**9+7
# memo_ls[i][j][k] : 上からi桁目まででMODがjでflgがkの個数
memo_ls = [[[0 for _k in range(2)] for j in range(d)] for i in range(digit_num + 1)]
memo_ls[0][0][0] = 1
dic = {j : j % d for j in range(10)}
for i, n in enumerate(K, 1):
    n = int(n)
    for j in range(10):
        for k in range(d):
            _from = (k - j) % d
            memo_ls[i][k][1] = (memo_ls[i][k][1] + memo_ls[i-1][_from][1]) % MOD
            if j == n:
                memo_ls[i][k][0] = (memo_ls[i-1][_from][0] + memo_ls[i][k][0]) % MOD
            elif j < n:
                memo_ls[i][k][1] = (memo_ls[i-1][_from][0] + memo_ls[i][k][1]) % MOD
print((sum(memo_ls[digit_num][0]) - 1) % MOD)