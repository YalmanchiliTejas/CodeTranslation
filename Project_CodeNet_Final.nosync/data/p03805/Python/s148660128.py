import sys
from sys import stdin
sys.setrecursionlimit(10**7)

def dfs(v, cnt):
    if cnt >= N-1:
        return 1
    seen[v] = True

    ret = 0
    for next_v in graph[v]:
        if seen[next_v]:
            continue
        ret += dfs(next_v, cnt+1)
    seen[v] = False
    return ret

if __name__ == "__main__":
    N, M = [int(_) for _ in stdin.readline().rstrip().split()]
    graph = [[] for _ in range(N)]
    seen = [False]*N
    for i in range(M):
        a, b = [int(_) for _ in stdin.readline().rstrip().split()]
        a, b = a-1, b-1
        graph[a].append(b)
        graph[b].append(a)
    print(dfs(0, 0))