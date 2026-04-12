from itertools import permutations

N, M = list(map(int, input().split()))
G = [[0 for _ in range(N + 1)] for _ in range(N + 1)]
for _ in range(M):
    ai, bi = list(map(int, input().split()))
    G[ai][bi] = 1
    G[bi][ai] = 1

count = 0
for idx, perm in enumerate(permutations(range(1, N+1))):
    if perm[0] != 1:
        continue

    flag = True
    for i in range(len(perm) - 1):
        if G[perm[i]][perm[i + 1]] == 0:
            flag = False
            break
    if flag:
        count += 1

print(count)