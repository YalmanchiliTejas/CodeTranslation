n = 0
g = []
res = 0


def dfs(i, path):
    global n, g, res
    path.append(i)
    if len(path) == n:
        res += 1
        path.pop()
        return

    for j in g[i]:
        if not j in path:
            dfs(j, path)
    path.pop()


def main():
    global n, g, res
    n, m = map(int, input().split())
    g = [set() for _ in range(n)]
    for _ in range(m):
        a, b = map(lambda s: int(s) - 1, input().split())
        g[a].add(b)
        g[b].add(a)

    path = []
    dfs(0, path)
    print(res)


if __name__ == '__main__':
    main()
