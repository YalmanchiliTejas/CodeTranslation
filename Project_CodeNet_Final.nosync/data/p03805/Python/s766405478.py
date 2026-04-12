import sys
sys.setrecursionlimit(10**7) #再帰関数の呼び出し制限
N, M = map(int, input().split())
A = [[0]* N for _ in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    A[a-1][b-1] = 1
    A[b-1][a-1] = 1
visited=[1]+[0]*(N-1)
def DFS(now, visited):
    ans = 0
    if not 0 in visited:
        return 1
    for i in range(N):
        if A[now][i] == 0:
            continue
        if visited[i] == 1:
            continue
        visited[i] = 1
        ans += DFS(i, visited)
        visited[i] = 0
    return ans
print(DFS(0, visited))