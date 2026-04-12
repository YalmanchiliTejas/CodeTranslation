a, b, c, x, y = map(int, input().split())
if 2*c>=a+b:
    print(a*x+b*y)
else:
    ans = min(x, y)*2*c
    if x>y:
        ans += min(a, 2*c)*(x-y)
    elif x<y:
        ans += min(b, 2*c)*(y-x)
    print(ans)