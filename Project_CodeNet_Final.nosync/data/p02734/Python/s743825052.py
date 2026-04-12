import sys
import math
def input():
    return sys.stdin.readline()[:-1]
n,s=map(int,input().split())
a = list(map(int,input().split()))
mod = 998244353
dp0 = [[0 for i in range(s+1)]for i in range(n+1)]
dp1 = [[0 for i in range(s+1)]for i in range(n+1)]
for i in range(1,n+1):
    for j in range(s+1):
        if j==0:
            b=1
        else:
            b=0
        dp0[i][j] += (dp0[i-1][j]+b)
        dp0[i][j] %= mod
        dp1[i][j] += (dp1[i-1][j]+dp0[i-1][j]+b)
        dp1[i][j] %= mod
        if j+a[i-1]<=s:
            dp0[i][j+a[i-1]] += (dp0[i-1][j]+b)
            dp0[i][j+a[i-1]] %= mod
            dp1[i][j+a[i-1]] += (b+dp0[i-1][j])
            dp1[i][j+a[i-1]] %= mod

        dp0[i][j]%=mod
        dp1[i][j]%=mod

print(dp1[n][s])
