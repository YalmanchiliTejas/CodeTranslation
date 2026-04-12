import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

N = int(input())
As = list(mapint())
mod = 10**9+7

SUM = sum(As)
ans = 0
for i, a in enumerate(As, 1):
    ans += a*(SUM-a)
    ans %= mod
print(ans*pow(2, mod-2, mod)%mod)