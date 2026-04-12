a,b,c,x,y = map(int,input().split())
z = 0
s=0
if a+b < c*2:
    z = a*x + b*y
else:
    mi = min(x,y)
    z = mi*2*c
    if x > y:
        s = (x-mi)*a
        if s > c * 2 * (x-mi):
            s = (x-mi)*c * 2
    else:
        s = (y-mi)*b
        if s > c * 2 * (y-mi):
            s = (y-mi)*c * 2
z += s
            
print(z)