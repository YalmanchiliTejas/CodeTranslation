from itertools import permutations
from math import factorial

N,M = map(int,input().split())
ab = set([tuple(map(int,input().split())) for _ in range(M)])

l = [i+1 for i in range(N)]
P = list(permutations(l))
P = P[:factorial(N-1)]

ans = 0
for p in P:
    path = True
    for i in range(len(p)-1):
        if not ((p[i],p[i+1]) in ab or (p[i+1],p[i]) in ab):
            path = False
            break
    if path:
        ans += 1

print(ans)
