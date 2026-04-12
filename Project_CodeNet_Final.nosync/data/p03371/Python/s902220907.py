a, b, c, x, y = map(int, input().split())
ave = (a + b) / 2

if c >= ave:
    ans = a * x + b * y
else:
    temp1 = c * max(x, y) * 2
    temp2 = c * min(x, y) * 2 + a * (x - min(x, y)) + b * (y - min(x, y))
    ans = min(temp1, temp2)
    
print(ans)