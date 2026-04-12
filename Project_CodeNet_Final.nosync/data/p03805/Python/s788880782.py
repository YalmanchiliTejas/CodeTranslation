import itertools


N, M = map(int, input().split())
edge = [[0] * (N+1) for _ in range(N+1)]
for i in range(M):
    a, b = map(int, input().split())
    edge[a][b] = 1
    edge[b][a] = 1

ans = 0
node = list(range(1, N+1))
for x in itertools.permutations(node):
    if x[0] == 1:
        for i in range(N-1):
            if not edge[x[i]][x[i+1]]:
                break
        else:
            ans += 1

print(ans)