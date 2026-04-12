visited, g = ([], [])

def dfs(i):
    visited[i] = True
    ans = 0
    if all(visited):
        visited[i] = False
        return 1
    for j, b in enumerate(g[i]):
        if b and not visited[j]:
            ans += dfs(j)
    visited[i] = False
    return ans


def main():
    global visited, g
    n, m = [int(i) for i in input().split()]
    visited = [False for i in range(n)]
    g = [[False for i in range(n)] for j in range(n)]
    for i in range(m):
        t, f = [int(j)-1 for j in input().split()]
        g[t][f] = True
        g[f][t] = True
    print(dfs(0))


if __name__ == '__main__':
    main()
