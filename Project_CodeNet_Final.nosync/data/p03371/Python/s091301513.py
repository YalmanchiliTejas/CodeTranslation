a, b, c, x, y = list(map(int, input().split()))
c *= 2
qwe = 0
if a + b > c:
    qwe = c * min(x, y)
else:
    qwe  = a * min(x, y) + b *min(x,y) 
for i in range(max(x, y) - min(x, y)):
    if x > y:
        if a < c:
            qwe += a
        else:
            qwe += c
    else:
        if b < c:
            qwe += b
        else:
            qwe += c
print(qwe)
