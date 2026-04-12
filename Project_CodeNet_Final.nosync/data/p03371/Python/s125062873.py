a, b, c, x, y = map(int, input().split())
price = min(a + b, 2 * c)
ans = min(x, y) * price
if x > y:
    ans += (x - y) * min(a, price)
else:
    ans += (y - x) * min(b, price)
print(ans)