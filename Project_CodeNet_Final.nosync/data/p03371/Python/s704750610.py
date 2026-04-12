a, b, c, x, y = map(int, input().split())
m = min(x, y)
ans = m * min(a + b, c * 2)

if x == m:
    ans += min(c * 2, b) * (y - m)
else:
    ans += min(c * 2, a) * (x - m)

print(ans)