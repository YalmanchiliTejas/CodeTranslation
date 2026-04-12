import sys
sys.setrecursionlimit(10 ** 9)
N, M = map(int, input().split())
G = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    G[a - 1].append(b - 1)
    G[b - 1].append(a - 1)
D = [0] * N
D[0] = 1

C = 0
def dfs(n):
    global C
    if not 0 in D:
        C += 1
        return
    for i in G[n]:
        if D[i] == 1:
            continue
        D[i] = 1
        dfs(i)
        D[i] = 0

dfs(0)
print(C)