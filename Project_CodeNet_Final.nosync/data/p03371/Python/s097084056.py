A, B, C, X, Y = map(int, input().split())

AB = min(A + B, C * 2)
A = min(A, C * 2)
B = min(B, C * 2)

ans = 0

if X > Y:
    X -= Y
    ans += AB * Y
    ans += A * X
else:
    Y -= X
    ans += AB * X
    ans += B * Y

print(ans)
