def main():
    n, m = map(int, input().split())
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v = map(lambda x: int(x) - 1, input().split())
        g[u].append(v)
        g[v].append(u)

    vis = [False] * n
    ans = dfs(0, g, vis, 0)

    print(ans)


def dfs(v, g, vis, count):
    vis[v] = True

    if all(vis):
        return count + 1

    for i in g[v]:
        if vis[i]:
            continue
        count = dfs(i, g, vis, count)
        vis[i] = False

    return count


if __name__ == '__main__':
    main()
