from math import floor
N,A,B,C,D = map(int,input().split())
mod = 10**9+7
factorials = [None for i in range(N+1)]
factorials[0] = 1
for i in range(1, N+1):
    factorials[i] = (factorials[i-1]*i) % mod
def inv(x):
    ret = 1
    k = mod - 2
    y = x
    while k:
        if (k & 1):
            ret = (ret * y) % mod
        y = (y * y) % mod
        k //= 2
    
    return ret

finv = [0]*(N+1)
finv[N] = inv(factorials[N])
for i in range(N, 0, -1):
    finv[i-1] = (finv[i]*i)%mod
def calc(i,j,k):
    tmp = finv[N-j]
    tmp = (tmp*finv[k])%mod
    tmp = (tmp*factorials[N-j+i*k])%mod
    y = finv[i]
    ret = 1
    while k:
        if (k & 1):
            ret = (ret * y) % mod
        y = (y * y) % mod
        k //= 2
    return (ret*tmp) % mod

dp = [[0]*(N+1) for _ in range(N+1)]
for i in range(B+1):
    dp[i][0] = 1
ls = [0]+list(range(C,D+1))
l = len(ls)
for i in range(A,B+1):
    for j in range(1,N+1):
        tmp = 0
        for k in ls:
            if k > j/i:
                break
            tmp = (tmp + dp[i-1][j-i*k]*calc(i,j,k)) % mod
        dp[i][j] = tmp
print(dp[B][N])