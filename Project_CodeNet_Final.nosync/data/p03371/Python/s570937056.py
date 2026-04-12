
a, b, c, x, y = map(int, input().split())
ans = 0

if a + b >= c * 2:
    if x < y:
        temp = a
        a = b
        b = temp
        temp = x
        x = y
        y = temp
    
    if a > 2 * c:
        ans = x * 2 * c
    else:
        ans = y * 2 * c + a * (x - y)
else:
    ans = a * x + b * y
print(ans)