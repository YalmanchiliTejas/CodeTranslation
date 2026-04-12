A, B, C, X, Y = map(int, input().split())

if A + B > 2 * C:
    ans = 2 * C * min(X, Y)
else:
    ans = A * min(X, Y) + B * min(X, Y)

Z = abs(X - Y)
D = A if X >= Y else B
if D > 2 * C:
    ans += 2 * C * Z
else:
    ans += Z * D

print(ans)
