a, b, c, x, y = map(int, input().split())

ans = x * a + y * b
if a + b > 2 * c:
    if x < y:
        ans = min(ans, 2 * c * x + b * (y - x))
    else:
        ans = min(ans, 2 * c * y + a * (x - y))
    ans = min(ans, 2 * c * max(x, y))
    
print(ans)