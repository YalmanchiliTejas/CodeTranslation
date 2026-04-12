a, b, c, x, y = map(int, input().split())

z = 0
ans = a*x + b*y
for i in range(max(x, y)):
    x = max(x-1, 0)
    y = max(y-1, 0)
    z += 2
    ans = min(ans, a*x + b*y + c*z)

print(ans)
