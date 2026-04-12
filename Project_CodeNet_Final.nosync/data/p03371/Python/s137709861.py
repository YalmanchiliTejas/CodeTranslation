A, B, C, X, Y = map(int, input().split())


if A + B <= C * 2:
    print(A * X + B * Y)
else:
    ans = C * max(X, Y) * 2

    cost = A if X > Y else B
    piece = max(X, Y) - min(X, Y)

    for i in range(piece):
        ans = min(ans, ans - 2 * C + cost)
    print(ans)
