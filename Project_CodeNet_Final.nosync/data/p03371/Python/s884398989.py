a, b, c, x, y = map(int, input().split())
if a + b < c * 2:
    ans = a * x + b * y
else:
    p1_cnt = max(x, y)
    p1_price = p1_cnt * c * 2
    p2_cnt = min(x, y)
    if p2_cnt == x:
        p2_price = p2_cnt * c * 2 + (y - x) * b
    else:
        p2_price = p2_cnt * c * 2 + (x - y) * a
    ans = min(p1_price, p2_price)
print(ans)