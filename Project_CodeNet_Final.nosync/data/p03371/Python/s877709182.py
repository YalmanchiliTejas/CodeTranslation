A, B, C, X, Y = map(int, input().split())

if A + B < 2 * C:
    print(A * X + B * Y)
else:  # ABピザを二枚ずつ増やしていく。最大は2(max(x,y))
    ans = float('inf')
    for i in range(0, max(X, Y) * 2 + 1, 2):
        ans = min(ans, max(A * (X - i // 2), 0) + max(B * (Y - i // 2), 0) + C * i)
    print(ans)
