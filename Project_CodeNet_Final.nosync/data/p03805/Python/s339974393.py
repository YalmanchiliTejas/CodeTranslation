N, M = map(int, input().split())

graph = [[0] * N for _ in range(N)]

for _ in range(M):
    i, j = map(int, input().split())
    graph[i - 1][j - 1] = 1
    graph[j - 1][i - 1] = 1

count = 0
i = 0
memo = []
def DepthFirstSearch(i):
    global count
    memo.append(i + 1)
    if len(memo) == N:
        count += 1
        return
    for j in range(N):
        if graph[i][j] == 1:
            if j+1 in memo:
                continue
            DepthFirstSearch(j)
            memo.pop()
    return count

print(DepthFirstSearch(i))