import itertools

n, m = map(int, input().split())
graph = [[0 for i in range(n)] for j in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    graph[a - 1][b - 1] = 1
    graph[b - 1][a - 1] = 1
ans = 0
for i in itertools.permutations(range(2, n + 1)):
    if not graph[0][i[0] - 1]:
        continue
    for j in range(n - 1):
        if j == n - 2:
            ans += 1
            break
        if not graph[i[j] - 1][i[j + 1] - 1]:
            break
print(ans)