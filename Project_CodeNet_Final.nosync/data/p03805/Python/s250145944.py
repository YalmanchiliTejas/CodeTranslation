import numpy as np
import itertools

n, m = map(int, input().split())
G = np.zeros((n, n), dtype = np.int64)
for i in range(m):
    u, v = map(int, input().split())
    G[u - 1][v - 1] = 1
    G[v - 1][u - 1] = 1

ans = 0
nums = [i for i in range(1, n)]
for perm in itertools.permutations(nums):
    path = [0] + list(perm)
    ok = True
    for i in range(n - 1):
        if G[path[i]][path[i + 1]] != 1:
            ok = False
            break
    ans += ok
print(ans)