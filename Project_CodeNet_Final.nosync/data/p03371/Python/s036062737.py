A, B, C, X, Y = map(int, input().split())

ans = None
n1 = A*X + B*Y
if X > Y:
    n2 = C * 2*Y + A * (X - Y)
    n3 = C * 2*X
    ans = min(n1, n2, n3)
else:
    n2 = C * 2*X + B * (Y - X)
    n3 = C * 2*Y
    ans = min(n1, n2, n3)

print(ans)
