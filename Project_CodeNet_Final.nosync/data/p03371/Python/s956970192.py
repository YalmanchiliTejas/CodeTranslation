a,b,c,x,y = map(int,input().split(" "))

if x>=y:
    tmp = min(c*y*2+a*(x-y), x*c*2)
else:
    tmp = min(c*x*2+b*(y-x), y*c*2)

print(min(tmp, a*x+b*y))