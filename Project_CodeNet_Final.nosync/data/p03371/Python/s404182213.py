a,b,c,x,y = map(int, input().split())

A = a*x + b*y
B = 2*c*max(x,y)

if x > y:
    C = y*2*c+(x-y)*a
else:
    C = x*2*c+(y-x)*b
print(min(A,B,C))
