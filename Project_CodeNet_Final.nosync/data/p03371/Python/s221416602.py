a, b, c, x, y = map(int, input().split())
ans = min(a + b, c * 2) * min(x, y)
if x > y:
    ans += (x - y) * min(a, c * 2)
elif y > x:
    ans += (y - x) * min(b, c * 2)
print(ans)