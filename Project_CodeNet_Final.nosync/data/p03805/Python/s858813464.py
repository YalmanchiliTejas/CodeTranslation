import itertools
import numpy as np
N, M = map(int, raw_input().split())
G = [map(int, raw_input().split()) for i in range(M)]
ans = 0
for x in itertools.permutations(range(1,N+1)):
    if x[0] != 1:
        continue
    ok = True
    for i in range(N-1):
        a, b = x[i:i+2]
        if (not [a, b] in G) and (not [b, a] in G):
            ok = False
            break
    if ok:
        ans += 1
print ans