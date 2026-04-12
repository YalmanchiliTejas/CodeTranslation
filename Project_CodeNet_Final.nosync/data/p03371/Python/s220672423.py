A, B, C, X, Y = map(int, input().split())
ans = 10**18
if Y < X:
    t = X
    X = Y
    Y = t
    t = A
    A = B
    B = t
for i in range(2 * Y + 1):
    if i % 2:
        continue
    x, y = max(0, X - i//2), max(0, Y - i//2)
    sub = C * i + A * x + B * y
    if sub < ans:
        ans = sub
print(ans)