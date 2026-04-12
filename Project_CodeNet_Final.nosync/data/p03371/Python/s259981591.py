a, b, c, x, y = map(int, input().split())
ans = x * a + y * b
if x > y:
    ans = min(ans, (x - y) * a + y * c * 2)
else:
    ans = min(ans, (y - x) * b + x * c * 2)
ans = min(ans, max(x, y) * c * 2)
print(ans)
