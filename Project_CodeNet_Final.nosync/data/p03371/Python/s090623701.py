a,b,c,x,y = map(int,input().split())

mi = min(x,y)
sa = abs(x-y)
if c*2 <= a+b:
    daikin = c*2*mi
    if x >= y:
        piza = min(c*2,a)
        daikin += piza*sa
    else:
        piza = min(c*2,b)
        daikin += piza*sa
    print(daikin)
else:
    print(a*x + b*y)
