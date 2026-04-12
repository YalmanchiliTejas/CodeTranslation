a,b,c,x,y = map(int,input().split())

if a+b < 2*c:
    ans = a*x+b*y
else:
    if x > y:
        if a > 2*c:
            ans = 2*c*x
        else:
            ans = a*(x-y)+2*c*y
    else:
        if b > 2*c:
            ans = 2*c*y
        else:
            ans = b*(y-x)+2*c*x

print(ans)