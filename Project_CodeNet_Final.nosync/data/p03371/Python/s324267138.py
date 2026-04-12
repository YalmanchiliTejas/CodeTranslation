a, b, c, x, y = map(int, input().split())
ans = 0


if a + b  >= c * 2:
    ans += (c * 2) * min(x,y)
    if x > y:
        ans += a * (x-y)
        if ans > (c * 2) * max(x,y):
            ans = (c * 2) * max(x,y)
    elif y > x:
        ans += b * (y-x)
        if ans > (c * 2) * max(x,y):
            ans = (c * 2) * max(x,y)

elif a + b < c * 2:
    ans = (a * x) + (b * y)


print(ans)