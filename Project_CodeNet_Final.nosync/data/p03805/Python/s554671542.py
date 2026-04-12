N,M = map(int,input().split())
vertex = [[0 for j in range(N+1)] for i in range(N+1)]

for i in range(M):
    a,b = map(int,input().split())
    vertex[a][b] = 1
    vertex[b][a] = 1

from itertools import permutations

ans = 0
for v in permutations([i+2 for i in range(N-1)], N-1):
    v = [1] + list(v)
    canmake = 1
    for j in range(N-1):
        if not vertex[v[j]][v[j+1]]:
            canmake = 0
            break
    if canmake:
        ans += 1
print(ans)