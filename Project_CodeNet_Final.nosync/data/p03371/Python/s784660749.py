a,b,c,x,y = map(int, input().split())
c_p = 2*c*min(x,y)
if x==y and (a+b)>c*2:
    print(c_p)
else:
    if x > y:
        price = min(c_p + (x-y)*a, c_p+(x-y)*c*2, a*x+b*y)
        print(price)
    elif x < y:
        price = min(c_p + (y-x) * b, c_p+(y-x)*c*2, a*x+b*y)
        print(price)
    else:
        print(a*x+b*y)