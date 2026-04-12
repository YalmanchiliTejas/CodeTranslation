a,b,c,x,y = map(int,input().split())
if x < y:
    a, b, x, y = b, a, y, x
print(min(a*x+b*y,2*c*y + a*(x-y),2*c*x))