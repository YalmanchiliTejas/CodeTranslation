def inpl():
    return list(map(int, input().split()))


A, B, C, X, Y = inpl()

ans = min(A + B, 2 * C) * min(X, Y)

if X > Y:
    ans += min(A, 2 * C) * (X - Y)
elif Y > X:
    ans += min(B, 2 * C) * (Y - X)

print(ans)
