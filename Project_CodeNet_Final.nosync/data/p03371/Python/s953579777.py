a,b,c,x,y=map(int, input().split())
z = 0#xy
l= []
l.append(a * x+b * y)
while x > 0 or y > 0:
    x -= 1
    y -= 1
    z += 2
    x1 = x
    if x1 < 0: x1 = 0
    y1 = y
    if y1 < 0: y1 = 0
    l.append(a * x1 + y1 * b + z * c)
print(min(l))