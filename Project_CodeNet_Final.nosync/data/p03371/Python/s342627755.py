a,b,c,x,y=map(int,input().split())
res1=a*x+b*y
if x>y:
    res2=c*2*y+a*(x-y)
else:
    res2=c*2*x+b*(y-x)
res3=c*2*max(x,y)
print(min(res1,res2,res3))