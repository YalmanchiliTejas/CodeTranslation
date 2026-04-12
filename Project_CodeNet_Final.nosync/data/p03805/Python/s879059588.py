from itertools import permutations
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
connected = [[False] * (N+1) for _ in range(N+1)]
for _ in range(M):
    a, b = map(int, input().split())
    connected[a][b] = connected[b][a] = True
ans = 0
for perm in permutations(list(range(2, N+1))):
    perm = (1,) + perm
    for i in range(N-1):
        u, v = perm[i], perm[i+1]
        if not connected[u][v]:
            break
    else:
        ans += 1
print(ans)