from itertools import permutations

N, M = map(int, input().split())

path_matrix = [[0]*N for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    path_matrix[a-1][b-1] = 1
    path_matrix[b-1][a-1] = 1

cnt = 0
for each in permutations(range(N)):
    if each[0] != 0:
        break

    factor = 1
    for i in range(N-1):
        factor *= path_matrix[each[i]][each[i+1]]
    cnt += factor

print(cnt)