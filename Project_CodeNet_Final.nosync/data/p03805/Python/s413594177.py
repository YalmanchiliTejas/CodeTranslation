import itertools
N, M = list(map(int, input().split()))
path = [[0 for i in range(N)] for j in range(N)]
for i in range(M):
    a, b = list(map(int, input().split()))
    path[a-1][b-1] = 1
    path[b-1][a-1] = 1

count = 0

for p in itertools.permutations(range(N)):
    if p[0] != 0:
        break
    check = 1
    for search in range(N-1):
        check = check * path[p[search]][p[search+1]]
    count += check

print(count)

