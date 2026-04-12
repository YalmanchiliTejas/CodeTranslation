a,b,c,x,y=map(int,input().split())
z=min(x,y)
if a+b>2*c:
    print(z*2*c+min((x-z)*a+(y-z)*b,(x+y-z*2)*2*c))
else:
    print(a*x+b*y)