a, b, c, x, y = list(map(int, input().split(' ')))

d = c * 2


ans = 1 << 30
# ABを何枚
for i in range(max(x, y) + 1):
    rx = max(x - i, 0)
    ry = max(y - i, 0)
    ans = min(ans,  i * d + rx * a + ry * b)
print(ans)
