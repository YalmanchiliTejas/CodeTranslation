from itertools import permutations
def inpl(): return [int(i) for i in input().split()]

N, M = inpl()
path = [[False]*N for _ in range(N)]


for _ in range(M):
    a,b = inpl()
    path[a-1][b-1] = path[b-1][a-1] = True

ans = 0
for i in permutations(range(1,N)):
    visited = 0
    for j in i:
        if not path[visited][j]:
            break
        visited = j
    else:
        ans += 1
print(ans)
