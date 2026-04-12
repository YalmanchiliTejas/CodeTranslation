a, b, c, x, y = map(int, input().split())
ans = 0
if 2*c <= a+b:
    ans += 2*c*min(x, y)
    if x >= y:
        ans += min(2*c, a)*(x-y)
    else:
        ans += min(2*c, b)*(y-x)
else:
    ans = a*x+b*y
print(ans)
