import sys
readline = sys.stdin.readline
sys.setrecursionlimit(10**8)
mod = 10**9+7
#mod = 998244353
INF = 10**18
eps = 10**-7

n = int(readline())
a = list(map(int,readline().split()))

cum = [0]*n

for i in range(n-2,-1,-1):
    cum[i] += cum[i+1] + a[i+1]
    cum[i] %= mod

ans = 0

for i in range(n):
    ans = (ans + a[i]*cum[i])%mod

print(ans)




