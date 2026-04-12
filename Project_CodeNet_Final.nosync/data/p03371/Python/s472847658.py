A, B, C, X, Y = map(int, input().split())

D = C * 2
p = []

if X > Y:
    p.append(D * Y + A * (X - Y))
else:
    p.append(D * X + B * (Y - X))

p.append(A * X + B * Y)
p.append(D * max(X, Y))

ans = min(p)

print(ans)
