import sys
 
stdin = sys.stdin

mod = 1000000007
inf = 1 << 60
 
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().rstrip()
nas = lambda: stdin.readline().split()

n = ni()
a = na()

m = 0
ans = 0
for i in range(n):
    m = max(m, a[i])
    if a[i] >= m:
        ans += 1

print(ans)