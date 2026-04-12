a, b, ab, x, y = map(int, input().split())

ans = 0
if a + b < 2 * ab:
    print(a * x + b * y)
else:
    ans += min(x, y) * 2 * ab
    if x > y:
        cost_one = min(a, 2 * ab)
        ans += cost_one * (x - y)
    else:
        cost_one = min(b, 2 * ab)
        ans += cost_one * (y - x)

    print(ans)
