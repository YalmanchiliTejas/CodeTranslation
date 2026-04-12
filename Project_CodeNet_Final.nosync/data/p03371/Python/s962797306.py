A, B, C, X, Y = map(int, input().split())

ans = 10**20
for i in range(max(X, Y) * 2 + 1):
    c = i
    a = X - i // 2
    if a < 0:
        a = 0
    b = Y - i // 2
    if b < 0:
        b = 0
    v = a * A + b * B + c * C
    if v < ans:
        ans = v

print(ans)
