a,b,c,x,y=[int(i) for i in input().split()]

if x>=y:
    print( min(y*2*c+a*(x-y), x*a+y*b, 2*c*x) )

else:
    print( min(x*2*c+b*(y-x), x*a+y*b, 2*c*y) )    