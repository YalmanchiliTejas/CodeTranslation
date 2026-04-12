a, b, c, x, y = map(int, input().split())
ans = a *x + b * y
m = max(x, y)
for i in range(m + 1):
    s = 2 * c * i
    s += max(x - i, 0) * a
    s += max(y - i, 0) * b
    if s < ans:
        ans = s
print(ans)