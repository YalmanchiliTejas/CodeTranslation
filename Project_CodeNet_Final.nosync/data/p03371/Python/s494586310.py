a, b, ab, x, y = map(int, input().split())
average = (a + b) / 2

if average <= ab:
    ans = a * x + b * y
else:
    temp1 = ab * min(x, y) * 2 + a * (x - min(x, y)) + b * (y - min(x, y))
    temp2 = ab * max(x, y) * 2
    ans = min(temp1, temp2)
    
print(ans)