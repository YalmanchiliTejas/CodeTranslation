import sys
stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
nn = lambda: list(stdin.readline().split())
ns = lambda: stdin.readline().rstrip()

h,w = na()
b = 0
for i in range(h):
    a = list(ns())
    b += a.count('#')

ans = 'Possible' if b == (h+w-1) else 'Impossible'
print(ans)