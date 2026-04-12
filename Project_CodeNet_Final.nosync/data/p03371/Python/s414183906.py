a,b,c,x,y=map(int,input().split())

mi=min(x,y)

pr=0

if c*2<=a+b :
    pr+=c*2*mi
    x-=mi
    y-=mi

#print(pr)

if c*2<a :
    pr+=c*2*x
else :
    pr+=a*x

if c*2<b :
    pr+=c*2*y
else :
    pr+=b*y

print(pr)
