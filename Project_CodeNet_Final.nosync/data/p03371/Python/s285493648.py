A, B, C, X, Y = map(int, input().split())
p1 = A * X
p2 = B * Y
ans = p1 + p2
mn = 2*max(X, Y)
for i in range(0, mn+1, 2):
    p1 = A*max(0, (X-(i//2)))
    p2 = B*max(0, (Y-(i//2)))
    ans = min(ans, p1+p2+i*C)

print(ans)
