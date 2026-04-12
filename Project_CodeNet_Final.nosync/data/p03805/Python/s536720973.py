from itertools import permutations

N, M = map(int, input().split())
lines = [[False] * 9 for _ in range(9)]
for _ in range(M):
    a, b = map(int, input().split())
    lines[a][b] = True
    lines[b][a] = True


counter = 0
for perm in permutations(range(2, N+1)):
    if lines[1][perm[0]]:
        if all(lines[perm[i]][perm[i+1]] for i in range(N-2)):
            counter += 1

print(counter)
