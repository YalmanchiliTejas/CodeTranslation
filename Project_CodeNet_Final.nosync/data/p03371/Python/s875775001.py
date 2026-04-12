a,b,c,x,y = [int(i) for i in input().split()]
if a>2*c and b>2*c:
        m = max(x,y)*2*c
elif a>2*c:
        if x>=y:
            m = x*2*c
        else:
            m=x*2*c+(y-x)*b
elif b>2*c:
        if y>=x:
            m=y*2*c
        else:
            m=y*2*c +(x-y)*a
elif a+b>2*c:
    if x>=y:
        d=a
    else:
        d=b
    m = min(x,y)*2*c+(max(x,y)-min(x,y))*d
else:
    m = x*a + y*b
print(m)