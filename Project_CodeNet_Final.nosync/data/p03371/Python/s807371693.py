a, b, ab, x, y = map(int, input().split())
ave = (a + b) / 2
minxy = min(x, y)
ans = 0

if ave > ab:
    ans += 2 * minxy * ab
    if x > y:
        if a < ab * 2:
            ans += (x - minxy) * a
        else:
            ans += (x - minxy) * 2 * ab
    else:
        if b < ab * 2:
            ans += (y - minxy) * b
        else:
            ans += (y - minxy)  * 2 * ab
else:
    ans = a * x + b * y
    
print(ans)