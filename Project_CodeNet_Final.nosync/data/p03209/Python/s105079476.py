N, X = map(int, input().split())


P, H = [1], [1]
for i in range(50):
    P.append(P[-1] * 2 + 1)
    H.append(H[-1] * 2 + 3)


def dfs(n, x):
    if x == 1:
        if n == 0:
            return 1
        else:
            return 0

    elif 1 < x <= H[n - 1] + 1:
        return dfs(n - 1, x - 1)

    elif x == H[n - 1] + 2:
        return P[n - 1] + 1

    elif H[n - 1] + 2 < x <= 2 * H[n - 1] + 2:
        return P[n - 1] + 1 + dfs(n - 1, x - H[n - 1] - 2)

    elif x == 2 * H[n - 1] + 3:
        return 2 * P[n - 1] + 1


print(dfs(N, X))

