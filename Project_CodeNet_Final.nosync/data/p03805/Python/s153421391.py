from itertools import permutations

N, M = map(int, input().split())

adjM = [[0] * N for v in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    adjM[a - 1][b - 1] = 1
    adjM[b - 1][a - 1] = 1

# 頂点を訪れる順番を全通り試す
ans = 0
for vs in permutations(range(1, N)):
    vs = [0] + list(vs)
    for i in range(N - 1):
        if adjM[vs[i]][vs[i + 1]] == 0:
            break
    else:
        ans += 1

print(ans)
