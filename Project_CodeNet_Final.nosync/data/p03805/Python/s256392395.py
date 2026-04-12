def dfs(n,G,visited,cnt):
    visited[n] = True
    if not False in visited:
        visited[n] = False
        return cnt + 1
    for x in G[n]:
        if visited[x] == True:
            continue
        cnt = dfs(x,G,visited,cnt)
    visited[n] = False
    return cnt


def main():
    N,M = map(int ,input().split())
    G = [list() for x in range(N)]
    for i in range(M):
        a,b = map(int,input().split())
        a = a - 1
        b = b - 1
        G[a].append(b)
        G[b].append(a)
    visited = [False] * N
    ans = dfs(0,G,visited,0)
    print(ans)

if __name__ == '__main__':
    main()
