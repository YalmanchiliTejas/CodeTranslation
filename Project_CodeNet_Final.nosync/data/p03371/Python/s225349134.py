a,b,c,x,y = map(int,input().split())
a1 = a*x + b*y
a2 = max(x,y) * 2*c
if y >= x:
    a3 = 2*c*x + (y-x)*b
else:
    a3 = 2*c*y + (x-y)*a
print(min(a1,a2,a3))