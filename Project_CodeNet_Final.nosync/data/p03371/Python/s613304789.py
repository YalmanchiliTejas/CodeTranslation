def resolve():
    A, B, C, X, Y = list(map(int, input().split()))
    MAX = 2 * max(X,Y)
    ans = 10 ** 14

    for i in range(MAX+1):
        ans = min(ans, A * max(X - i, 0) + B * max(Y - i, 0) + 2 * C * i)

    print(ans)
    return

resolve()
