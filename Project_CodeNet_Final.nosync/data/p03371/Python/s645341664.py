a,b,c,x,y=map(int,input().split())
d={x:a,y:b}
if a+b >= 2*c:
    if d[max(x,y)] >= 2*c:
        print(max(x,y)*2*c)
    else:
        print(min(x,y)*2*c + abs(x-y)*d[max(x,y)])
else:
    print(a*x + b*y)