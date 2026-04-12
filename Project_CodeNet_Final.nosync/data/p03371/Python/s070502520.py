a, b, c, x, y = map(int, input().split())
if x == y:
    ans = min(x * a + y * b, x * 2 * c)
elif x > y:
    ans = min(x * a + y * b, x * 2 * c, y * 2 * c + (x - y) * a)
else:
    ans = min(x * a + y * b, y * 2 * c, x * 2 * c + (y - x) * b)
print(ans)