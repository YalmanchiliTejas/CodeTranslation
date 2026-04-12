a, b, ab, x, y = map(int, input().split())
ave = (a + b) / 2

if ave > ab:
    amt = ab * min(x, y) * 2
    if x > y:
        if a > ab * 2:
            amt += ab * (x - y) * 2
        else:
            amt += a * (x - y)
    else:
        if b > ab * 2:
            amt += ab * (y - x) * 2
        else:
            amt += b * (y - x)
else:
    amt = a * x + b * y
    
print(amt)