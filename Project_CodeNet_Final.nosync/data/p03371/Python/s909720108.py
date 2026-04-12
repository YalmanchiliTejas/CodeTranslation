a,b,c,x,y=list(map(int,input().split()))
mi=min(x,y)
if a+b>=c*2:
    print(min(mi*2*c+(x-mi)*a+(y-mi)*b,c*2*max(x,y)))
else:
    print(a*x+b*y)