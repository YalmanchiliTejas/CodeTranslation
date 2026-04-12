from itertools import permutations

N, M = map(int, input().split())
matrix = [[0] * N for i in range(N)]
ans = 0

for i in range(M):
    a, b = map(int, input().split())
    matrix[a-1][b-1] = 1
    matrix[b-1][a-1] = 1

for p in list(permutations(range(N))):
    if p[0] != 0:
        continue
    else:
        check = 1
        for i in range(N - 1):
            check *= matrix[p[i]][p[i+1]]
        ans += check

print(ans)