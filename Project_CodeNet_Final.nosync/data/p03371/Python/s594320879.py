a,b,c,x,y = map(int, input().split(" "))
sum = 0
if a+b >= c*2:
    v = min(x, y)
    for i in range(v):
        sum += 2*c
    x -= v
    y -= v

if a < c*2:
    sum += a*x
if b < c*2:
    sum += b*y
if a >= c*2:
    sum += 2*c*x
if b >= c*2:
    sum += 2*c*y
print(sum)