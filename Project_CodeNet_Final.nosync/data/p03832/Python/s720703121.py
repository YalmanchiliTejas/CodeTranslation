from itertools import*
import math
from collections import*
from heapq import*
from bisect import bisect_left,bisect_right
from copy import deepcopy
inf = 10**18
mod = 10**9+7
from functools import reduce
import sys
sys.setrecursionlimit(10**7)

n,a,b,c,d = map(int,input().split())
Max = 1005
#二項係数とその逆元テーブルを作る前処理
fac = [0]*(Max)
finv = [0]*(Max)
inv = [0]*(Max)
fac[0]=fac[1]=1
finv[0]=finv[1]=1
inv[1]=1
for i in range(2,Max):
        fac[i] = fac[i-1] * i % mod
        inv[i] = mod - inv[mod%i]*(mod//i)%mod
        finv[i] = finv[i-1]*inv[i]%mod
#O(1)でmod計算した組合せ数を計算
def C(n,r):
    if n < r:
        return 0
    if n < 0 or r < 0 :
        return 0
    return fac[n]*(finv[r]*finv[n-r]%mod)%mod
#mod計算した順列の計算
def P(n,r):
    if n < r:
        return 0
    if n<0 or r<0:
        return 0
    return (fac[n]*finv[n-r])%mod

#dp[i][j]:i人以下のグループだけでj人使っている場合の数
dp = [[0]*(n+1) for i in range(n+1)]
for i in range(n+1):
    dp[i][0]=1

for i in range(a,b+1):
    for j in range(1,n+1):
        dp[i][j] = dp[i-1][j]
        k = c
        while k <= j//i and k <= d:
            x = (fac[j] * finv[j - k * i] * finv[k] * pow(finv[i], k, mod)) % mod
            dp[i][j] += (dp[i - 1][j - k * i] * x) % mod
            k += 1
        dp[i][j] %= mod
print(dp[b][n])