a,b,c,x,y=map(int,input().split())

res1=a*x+b*y
if x>y:
    res2=2*y*c+(x-y)*a
else:
    res2=2*x*c+(y-x)*b
res3=2*max(x,y)*c
print(min(res1,res2,res3))