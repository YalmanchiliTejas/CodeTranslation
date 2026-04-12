a, b, c, x, y = map(int, input().split())
ans = 0
c = 2*c

if x > y:
    if c < a:
        ans = c*x
    elif c < a+b:
        ans = c*y + a*(x-y)
    else:
        ans = a*x + b*y
else:
    if c < b:
        ans = c*y
    elif c < a+b:
        ans = c*x + b*(y-x)
    else:
        ans = a*x + b*y
print(ans)