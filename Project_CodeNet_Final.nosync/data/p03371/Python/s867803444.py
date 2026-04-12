a, b, c, x, y = map(int, input().split())
z = 0
p = 0
if a+b < c*2:
    p = a*x + b*y
else:
    if x > y:
        x -= y
        z = y*2
        y = 0
        if a > c*2:
            z += x*2
            x = 0
    else:
        y -= x
        z = x*2
        x = 0
        if b > c*2:
            z += y*2
            y = 0
            
print(x*a + y*b + z*c)
    