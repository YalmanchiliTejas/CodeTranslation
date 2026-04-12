a,b,c,x,y=map(int,input().split())

if x >= y:
    print(min(a*x+b*y , 2*x*c , 2*c*y + a*(x-y)))

else:
    print(min(a*x+b*y , 2*y*c , 2*c*x + b*(y-x)))
    