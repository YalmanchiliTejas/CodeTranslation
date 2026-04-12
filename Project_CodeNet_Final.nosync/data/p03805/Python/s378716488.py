
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)
##############################

# https://atcoder.jp/contests/abc054/tasks/abc054_c

# N = 頂点の数(= 数字の数)
# M = 辺の数(= aの行数)

N, M = map(int, input().split())
graph = [ [0 for _ in range(N)] for _ in range(N) ]
visited = [False] * N

for i in range(M):
    a, b = map(int, input().split())
    graph[a-1][b-1] = 1
    graph[b-1][a-1] = 1

#print(graph)

# u は 0-index
def dfs(u):
    if False in visited:
        pass
    else:
        return 1

    count = 0
    for i in range(N):
        if graph[u][i] == False: continue
        if visited[i]: continue

        visited[i] = True
        count += dfs(i)
        visited[i] = False

    return count

visited[0] = True
count = dfs(0)
print(count)