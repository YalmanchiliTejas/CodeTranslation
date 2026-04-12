import itertools

N, M = map(int, input().split())

path_matrix = []

# 無向グラフの作成
for n in range(N):
    path_matrix.append([0] * N)

for m in range(M):
    paths = [int(i) - 1 for i in input().split()]
    path_matrix[paths[0]][paths[1]] = 1
    path_matrix[paths[1]][paths[0]] = 1

list_per = list(itertools.permutations(range(N)))
ans = 0

for i in list_per:
    if i[0] != 0:
        break
    cnt = 1
    for index in range(N - 1):
        cnt *= path_matrix[i[index]][i[index + 1]]
    ans += cnt
    
print(ans)
