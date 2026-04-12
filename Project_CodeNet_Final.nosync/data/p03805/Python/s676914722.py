import sys
sys.setrecursionlimit(10**7)


def dfs(v):
    global ans
    if all(visited[i] == 1 for i in range(n)):
        ans = ans + 1
        return
    for i in range(n):
        if gra[v][i] == 1 and visited[i] == 0:
            visited[i] = 1
            dfs(i)
            visited[i] = 0
    return


if __name__ == '__main__':
    n, m = map(int, input().split())
    ans = 0
    visited = [0]*n
    gra = [[0]*n for _ in range(n)]
    visited[0] = 1
    for _ in range(m):
        a, b = map(lambda x: int(x) - 1, input().split())
        gra[a][b] = 1
        gra[b][a] = 1
    dfs(0)
    print(ans)