from itertools import permutations

N, M = map(int, input().split())
pe = permutations([i for i in range(N)])

matrix = [[0] * N for _ in range(N)]
for _ in range(M):
    u, v = map(int, input().split())
    matrix[u - 1][v - 1] = 1
    matrix[v - 1][u - 1] = 1

cnt = 0
for p in pe:
    for i in range(N - 1):
        if i == 0 and p[i] != 0:
            break
        if matrix[p[i]][p[i + 1]] == 1:
            continue
        else:
            break
    else:
        cnt += 1
print(cnt)
