a,b,c,x,y = list(map(int,input().split()))
ret = 0
if a+b > c*2:
    targetPizza = 0
    if x>y:
        x -= y
        ret += y*c*2
        y = 0
        if c*2 < a:
            ret += c*2*x
            x = 0

    else:
        y -= x
        ret += x*c*2
        x = 0
        if c*2 < b:
            ret += c*2*y
            y = 0
ret += a*x
ret += b*y
print(ret)
