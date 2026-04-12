a, b, c, x, y = map(int, input().split())

ans = 0
if a+b > c*2:
    xy = max(x, y)-abs(x-y)
    ans = c*xy*2
    x -= xy
    y -= xy
    if a <= c*2 and b <= c*2:
        ans += a*x+b*y
    elif a > c*2 and x > 0:
        ans += c*x*2
        y -= x
        if y > 1:
            ans += b*y
    else:
        ans += c*y*2
        x -= y
        if x > 1:
            ans += a*x
else:
    ans = a*x+b*y

print(ans)
