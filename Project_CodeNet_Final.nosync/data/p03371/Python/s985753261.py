a, b, c, x, y = map(int, input().split())
ans = 0
if a+b >= 2*c:
    if x >= y:
        ans += 2*c*y
        ans += min(a, 2*c)*(x-y)
    else:
        ans += 2*c*x
        ans += min(b, 2*c)*(y-x)
else:
    ans = x*a+y*b
print(ans)
