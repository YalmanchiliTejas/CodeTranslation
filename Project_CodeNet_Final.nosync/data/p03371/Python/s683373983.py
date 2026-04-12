a, b, c, x, y = map(int, input().split())
if a + b <= 2 * c:
    print(a * x + b * y)
else:
    z = min([x,y])
    ans = min([c*z*2+a*(x-z)+b*(y-z), c*max([x,y])*2])
    print(ans)