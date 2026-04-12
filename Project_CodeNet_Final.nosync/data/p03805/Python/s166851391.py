import itertools

N, M = map(int, input().split())
graph = [[0] * N for i in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    graph[a-1][b-1] = 1
    graph[b-1][a-1] = 1

p = list(itertools.permutations(range(N)))

Sum = 0

for i in range(len(p)):
    if p[i][0] != 0:
        break
    for j in range(N - 1):
        if graph[p[i][j]][p[i][j + 1]] != 1:
            break
        elif j == N - 2:
            Sum += 1

print(Sum)