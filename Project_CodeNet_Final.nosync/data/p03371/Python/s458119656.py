a,b,c,x,y= map(int, input().split())
p=[0]*3
p[0]=a*x+b*y
if x<=y:
    p[1]=2*c*y
    p[2]=2*c*x+b*(y-x)
elif x>y:
    p[1]=2*c*x
    p[2]=a*(x-y)+2*c*y
print(min(p))
