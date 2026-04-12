import sys
stdin = sys.stdin
sys.setrecursionlimit(10**6)
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
nn = lambda: list(stdin.readline().split())
ns = lambda: stdin.readline().rstrip()

n = ni()
a = na()
aa = a[::-1]
mod = 10**9+7

for i in range(1,n):
    aa[i] = aa[i]+aa[i-1]

aa = aa[::-1]
ans = 0

for i in range(n-1):
    ans += a[i]*aa[i+1]%mod

print(ans%mod)