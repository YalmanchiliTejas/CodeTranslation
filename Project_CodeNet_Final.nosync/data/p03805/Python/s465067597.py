from itertools import permutations

N, M = map(int, input().split())
G = [[0] * N for _ in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    G[a - 1][b - 1] = 1
    G[b - 1][a - 1] = 1

count = 0
for p in permutations(range(1, N)):
    s = 0
    for i in p:
        if G[s][i] == 0:
            break
        else:
            s = i
    else:
        count += 1

print(count)