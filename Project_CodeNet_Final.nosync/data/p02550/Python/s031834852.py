import sys

sys.setrecursionlimit(500005)
stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().strip()

n, x, m = na()
hit = {}
hit[x] = 0
a = [x]

pe = -1
while True:
    v = a[-1] * a[-1] % m
    if v in hit:
       pe = len(a)-hit[v]
       break
    a.append(v)
    hit[v] = len(a)-1
ta = len(a) - pe
if n <= len(a):
    print(sum(a[0:n]))
else:
    cy = (n-ta) // pe
    u = (n-ta) % pe + ta
    print(sum(a[0:u]) + cy*sum(a[ta:]))
