a, b, c, x, y = map(int, input().split())

if a+b < 2*c:
    ans = a*x + b*y
else:
    if x < y:
        ans = 2*c * x + b*(y-x)
    elif y < x:
        ans = 2*c * y + a*(x-y)
    else:
        ans = 2*c*x
    ans = min(ans, 2*c*max(x,y))

print(ans)