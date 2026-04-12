import sys
stdin = sys.stdin
sys.setrecursionlimit(10**6)
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
nn = lambda: list(stdin.readline().split())
ns = lambda: stdin.readline().rstrip()

n = ni()
a = []

for i in range(n):
    a.append(ni())

a.sort()
t = n//2

if n%2 == 0:
    ans = (sum(a[t+1:])-sum(a[:t-1]))*2+a[t]-a[t-1]
    print(ans)
else:
    x = 2*(sum(a[t+1:])-sum(a[:t-1])) - a[t-1] - a[t]
    y = 2*(sum(a[t+2:])-sum(a[:t])) + a[t+1] + a[t]
    print(max(x,y))