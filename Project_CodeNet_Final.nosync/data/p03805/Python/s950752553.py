def main():
    N, M = map(int, input().split())
    edges = [[] for _ in range(N)]
    for _ in range(M):
        a, b = map(lambda x: int(x)-1, input().split())
        edges[a].append(b)
        edges[b].append(a)

    visited = [False]*N
    visited[0] = True
    ans = 0

    def dfs(v: int):
        nonlocal visited
        nonlocal ans
        if all(visited):
            ans += 1
            return
        for n in edges[v]:
            if visited[n]:
                continue
            visited[n] = True
            dfs(n)
            visited[n] = False
        return

    dfs(0)
    print(ans)


if __name__ == "__main__":
    main()
