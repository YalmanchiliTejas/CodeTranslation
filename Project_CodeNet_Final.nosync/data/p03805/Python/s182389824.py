from itertools import permutations

N, M = map(int, input().split())
G = [[0]*N for _ in range(N)]

for _ in range(M):
    a, b = map(int, input().split())
    G[a-1][b-1] = 1
    G[b-1][a-1] = 1

ans = 0

for p in permutations(range(N)):
    now = p[0]
    
    if now!=0:
        continue

    for i in range(1, N):
        if G[now][p[i]]==1:
            now = p[i]
        else:
            break
    else:
        ans += 1

print(ans)