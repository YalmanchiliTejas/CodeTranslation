a,b,c,x,y = map(int,input().split())
temp = 0
if x > y:
    temp = min(a*x+b*y,a * (x-y) + c * 2 * y,c * 2 * x)
else:
    temp = min(a*x+b*y,b * (y-x) + c * 2 * x,c * 2 * y)
print(temp)
