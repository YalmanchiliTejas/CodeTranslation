a, b, ab, x, y = map(int, input().split())
ave = (a + b) / 2
ans = 0

if ab >= ave:
    ans += a * x + b * y
else:
    if x > y:
        ans += ab * y * 2
        if a > ab * 2:
            ans += ab * (x - y) * 2
        else:
            ans += a * (x - y)
    else:
        ans += ab * x * 2
        if b > ab * 2:
            ans += ab * (y - x) * 2
        else:
            ans += b * (y - x)
        
print(ans)