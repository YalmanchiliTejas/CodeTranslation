a,b,c,x,y = map(int, input().split())
if b < a:
    a,b = b,a
    x,y = y,x
if c >= (a+b)/2:
    ans = a*x + b*y
else:
    ans = c*min(x,y)*2
    if x >= y:
        if 2*c > a:
            ans += (x-y)*a
        else:
            ans += (x-y)*2*c
    else:
        if 2*c > b:
            ans += b*(y-x)
        else:
            ans += c*(y-x)*2
print(ans)
