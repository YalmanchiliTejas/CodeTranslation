A, B, C, X, Y = map(int, input().split())
C *= 2
if X == Y:
    print(min((A * X + B * Y, C * X)))
elif X > Y:
    ans = 0
    ans += min(C * Y, A * Y + B * Y)
    num = X - Y
    ans += min(C, A) * num
    print(ans)
elif Y > X:
    ans = 0
    ans += min(C * X, A * X + B * X)
    num = Y - X
    ans += min(C, B) * num
    print(ans)
