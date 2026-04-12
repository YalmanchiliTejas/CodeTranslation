a, b, c, x, y = map(int, input().split())
n = min(x,y)
res = 0
if a+b > c*2:
    prod = c*n*2
    x -= n
    y -= n
    res += prod

if x > y:
    if a - c*2 > 0:
        res += c*2*x
        x -= x
else:
    if b - c*2 > 0:
        res += c*2*y
        y -= y

res += a*x + b*y
print(res)