a, b, c, x, y = map(int, input().split())

if a+b >= 2*c:
    if x >= y:
        ans = y*c*2
        ans = ans+min((x-y)*a, (x-y)*2*c)
    else:
        ans = x*c*2
        ans = ans+min((y-x)*b, (y-x)*2*c)
else:
    ans = a*x + b*y

print(ans)
