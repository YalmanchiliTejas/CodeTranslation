N, X = map(int, input().split())
table = [None] * (N + 1)
table[0] = (1, 1)


def check_X(x, p):
    if x >= X:
        print(p)
        exit()


def dfs(n, x, p):
    check_X(x, p)
    if table[n] is None or x + table[n][0] > X:
        # バン
        new_x, new_p = x + 1, p

        # L-1バーガー
        new_x, new_p = dfs(n - 1, new_x, new_p)
        check_X(new_x, new_p)

        # パティ
        new_x += 1
        new_p += 1

        # L-1バーガー
        new_x, new_p = dfs(n - 1, new_x, new_p)

        # バン
        new_x += 1
        check_X(new_x, new_p)

        table[n] = (new_x - x, new_p - p)
        return new_x, new_p
    else:
        dx, dp = table[n]
        return x + dx, p + dp


dfs(N, 0, 0)
