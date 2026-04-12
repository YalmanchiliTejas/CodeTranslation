a,b,c,x,y=map(int,input().split())
z=min(x,y)
if a+b<2*c:
    print(a*x+b*y)
else:
    print(c*2*z+min((x-z)*a+(y-z)*b,2*c*(x+y-2*z)))