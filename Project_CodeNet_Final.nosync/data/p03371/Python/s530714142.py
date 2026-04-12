a, b, c, x, y = map(int, input().split())
s = 0
if a+b > 2*c:
    if x >= y:
        s = 2*y*c + (x-y)*min([a, 2*c])
    else:
        s = 2*x*c + (y-x)*min([b, 2*c])
else:
    if x >= y:
        s = y*(a+b) + (x-y)*min([a, 2*c])
    else:
        s = x*(a+b) + (y-x)*min([b, 2*c])

print(s)
