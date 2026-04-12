a,b,c,x,y = map(int,input().split())
ans = 0

if c*2 <= a+b:
    m = min(x,y)
    ans += m*c*2
    x -= m
    y -= m
    if 0 < x and c*x*2 < a*x:
        ans += (c*x*2)
    elif 0 < y and c*y*2 < b*y:
        ans += (c*y*2)
    else:
        ans += (a*x)+(b*y)
else:
    ans = (a*x)+(b*y)

print(ans)