
import sys
input = sys.stdin.readline
sys.setrecursionlimit(2147483647)
INF=float("inf")
MOD=10**9+7
# A = [ int(input()) for _ in range(N) ]
##############################

N, M = map(int, input().split())

A = [ [0 for _ in range(N)] for _ in range(N) ]
visited = [False] * N

for i in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    A[a][b] = 1
    A[b][a] = 1

#print(A)

def dfs(node, count):
    if all(visited):
        return count+1

    for i in range(N):
        if A[node][i] == 0:
            continue
        if visited[i]:
            continue

        visited[i] = True
        count = dfs(i, count)
        visited[i] = False

    return count


visited[0] = True
count = dfs(0, 0)
print(count)
