import sys
sys.setrecursionlimit(10**5)
def solve():
    N,M = map(int,input().split())
    G = [[False]*N for _ in range(N)]
    for _ in range(M):
        a, b = map(int,input().split())
        a -= 1
        b -= 1
        G[a][b] = True
        G[b][a] = True
    
    visited = [False] * N
    print(dfs(0, G, visited[:], N))

def dfs(now, G, visited, N):
    visited[now] = True
    if not (False in visited):
        return 1
    
    cnt = 0
    for next in range(N):
        if not visited[next] and G[now][next]:
            cnt += dfs(next,G,visited[:],N)
    
    return cnt

if __name__ == '__main__':
    solve()