a,b,c,x,y=map(int,input().split())
price=0
z=min(x,y)
w=max(x,y)
if a+b>c*2:
    d=w*2*c
    e=z*c*2+(x-z)*a+(y-z)*b
    print(min(e,d))

else:
    print(a*x+b*y)
