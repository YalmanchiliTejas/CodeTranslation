a,b,c,x,y = map(int,input().split())
d = []
d.append(a*x+b*y)
if x >= y:
    d.append(a*(x-y)+c*y*2)
    d.append(c*x*2)
else:
    d.append(b * (y - x) + c * x * 2)
    d.append(c * y * 2)
print(min(d))
