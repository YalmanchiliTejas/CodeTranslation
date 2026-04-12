a, b, c, x, y = map(int, input().split())
ans = 0
if a + b < c * 2:
    ans = x * a + y * b
else:
    if x <= y:
        # 余計にできる場合も考える
        ans = min(2 * c * x + b * (y - x), 2 * c * y)
    else:
        ans = min(2 * c * y + a * (x - y), 2 * c * x)
print(ans)
