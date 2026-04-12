def dfs(now, depth):
    if used[now]:
        return 0
    if depth == N:
        return 1

    used[now] = 1
    ans = 0

    for i in range(N):
        if connect[now][i]:
            ans += dfs(i, depth + 1)

    used[now] = 0
    return ans


def main():

    for i in range(M):
        connect[a[i]][b[i]], connect[b[i]][a[i]] = 1, 1

    print(dfs(0, 1))


if __name__ == '__main__':
    N, M = map(int, input().split())
    a = [0 for i in range(M)]
    b = [0 for i in range(M)]

    for i in range(M):
        ai, bi = map(int, input().split())
        a[i] = ai - 1
        b[i] = bi - 1

    used = [0 for i in range(N)]
    connect = [[0 for i in range(N)] for i in range(N)]
    main()
