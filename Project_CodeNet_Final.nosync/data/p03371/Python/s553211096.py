a, b, ab, x, y = [int(i) for i in input().split()]

if a + b < 2 * ab:
    print(a * x + b * y)

else:
    ans = min(x, y) * 2 * ab
    if x > y:
        ans += min((x - y) * 2 * ab, (x - y) * a)
    elif y > x:
        ans += min((y - x) * 2 * ab, (y - x) * b)

    print(ans)
