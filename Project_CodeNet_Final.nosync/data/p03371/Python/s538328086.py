a,b,c,x,y = map(int, input().split())

A = a * x + b * y
if min(x,y) == x:
    B = c * x * 2 + (y-x) * b
    C = c * y * 2
else:
    B = c * y * 2 + (x-y) * a
    C = c * x * 2

print(min(A,B,C))