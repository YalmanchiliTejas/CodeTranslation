a,b,c,x,y = map(int,input().split())

if min(a,b)>=2*c:
    print(max(x,y)*2*c)
elif a+b>=2*c:
    if x==y:
        print(x*2*c)
    elif x>y:
        print(y*2*c+(x-y)*min(a,2*c))
    else:
        print(x*2*c+(y-x)*min(b,2*c))
else:
    print(a*x+b*y)
