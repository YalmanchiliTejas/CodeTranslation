A, B, C, X, Y = map(int, input().split())
ans = A * X + B * Y
for z in range(0, 2*max(X, Y)+1, 2):
    a = C*z + A * max(0,X - z//2) + B * max(0, Y - z//2)
    ans = min(ans, a)
print(ans)