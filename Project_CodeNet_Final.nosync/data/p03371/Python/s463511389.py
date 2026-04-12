a,b,c,x,y = map(int,input().split())
if x>=y:
    res = min([2*x*c, 2*y*c+a*(x-y), a*x+b*y])
else:
    res = min([2*y*c, 2*x*c+b*(y-x), a*x+b*y])
print(res)